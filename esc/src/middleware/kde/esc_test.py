#!/usr/bin/env python3
"""
esc_test.py - automatska test sekvenca za KDE ESC-ove preko MAVLink-a (UDP).

Ista sekvenca kao droneCAN/kde/.../droncan/esc_control.py (MAV_CMD_USER_1
verzija), samo sto ovde ide PWM po ESC-u (MAV_CMD_DO_SET_SERVO) kroz isti
link kao esc_control.py:

    ARM -> nule 10s -> throttle rampa 0 -> hover za 15s + dwell 5s
        -> ROLL  +10 -10 +20 -20 +30 -30 deg, po 3s
        -> PITCH isto
        -> YAW   isto
        -> rampa nadole do 0 za 3s + dwell 5s -> minimum

Korak u stepenima postaje komanda kao u originalu: amp = deg * *_AMP_SCALE
(10 deg -> 0.05), pa ide kroz X-quad mixer

    M1 = T + P + R - Y      M2 = T + P - R + Y
    M3 = T - P - R - Y      M4 = T - P + R + Y      (klip na MOTOR_IDLE..1)

i na kraju u PWM: --min + m * (--max - --min). Motori idu na ESC-ove redom iz
--escs (M1 = prvi ID, ...), sa podrazumevanim 2,3,4,5: M1=ESC2 ... M4=ESC5.
Ako se zada manje ID-jeva, motor bez ESC-a se racuna i upisuje u log, ali se
ne salje.

Log i prosledjivanje telemetrije na drugi uredjaj rade u ovoj istoj skripti,
isto kao u esc_control.py (EscLogger / TelemetryForwarder). Log ima prefiks
esc_test_, a u grupi setpoint/ je i faza sekvence i T/R/P/Y.

Tastatura: q / x / space / Ctrl+C -> prekid: minimum (bez DISARM-a).

Koriscenje:
    python3 esc_test.py --plan                  # samo ispise sekvencu
    python3 esc_test.py
    python3 esc_test.py --axes yaw,roll --hover 0.4
    python3 esc_test.py --escs 2,3,4,5 --fwd-ip 192.168.1.160 --no-log

===========================================================================
TOK PROGRAMA (main)
===========================================================================
    1. parse_args()          argumenti komandne linije
    2. build_sequence()      lista faza redom (ZERO, THROTTLE RAMP, ROLL +10deg...)
       Sequence              za vreme t od pocetka kaze koja je faza i koliki
                             su T (gas), R (roll), P (pitch), Y (yaw)
    3. --plan                samo print_plan() i kraj, nista se ne salje
    4. EscLink, open_outputs isto kao esc_control.py (socket, log, fwd)
    5. arm_fleet()           ARM i ~6s cekanja
    6. run_sequence()        petlja, svakih par ms:
          t -> Sequence.at(t) -> T,R,P,Y -> mix() -> 4 motora 0..1
            -> motor_pwms() -> PWM po ESC-u -> salje se SLEDECEM ESC-u
    7. shutdown()            minimum, bez DISARM-a - uvek, i kad se prekine
"""

import argparse
import bisect
import collections
import time

from esc_control import (
    DEF_ESC_IDS,
    PRINT_PERIOD_S,
    EscLink,
    Keyboard,
    StatusView,
    Ticker,
    add_link_args,
    arm_fleet,
    armed_text,
    bar_text,
    check_link_args,
    device_lines,
    fwd_state_text,
    install_stop_signals,
    link_state_text,
    open_outputs,
    parse_id_list,
    shutdown,
    sleep_until,
)

# ============================================================================
# MACRO CONFIG - iste vrednosti kao u droneCAN esc_control.py
# ============================================================================
THROTTLE_HOVER    = 0.6
MOTOR_IDLE        = 0.0

# --- Throttle ramp ---
THROTTLE_MIN      = MOTOR_IDLE
THROTTLE_RAMP_T   = 15.0
THROTTLE_DWELL_T  = 5.0

# --- Throttle ramp-down (na kraju sekvence) ---
THROTTLE_RAMP_DOWN_T  = THROTTLE_RAMP_T / 5
THROTTLE_DWELL_DOWN_T = THROTTLE_DWELL_T

# --- Step sweep opste ---
BETWEEN_PAUSE     = 1.5
ZERO_SEQ_ON_START = 10.0
STEP_GAP_T        = 0.1     # hover izmedju +/- para
SWEEP_TAIL_T      = 0.5     # hover na kraju svake ose

# --- Roll step sweep ---
ROLL_STEP_DEG  = 10
ROLL_MAX_DEG   = 30.0
ROLL_HOLD_T    = 3
ROLL_AMP_SCALE = 0.005

# --- Pitch step sweep ---
PITCH_STEP_DEG  = 10
PITCH_MAX_DEG   = 30.0
PITCH_HOLD_T    = 3
PITCH_AMP_SCALE = 0.005

# --- Yaw step sweep ---
YAW_STEP_DEG  = 10
YAW_MAX_DEG   = 30.0
YAW_HOLD_T    = 3
YAW_AMP_SCALE = 0.005

# Podesavanja jedne ose:
#   label   ime u ispisu i logu ("ROLL")
#   field   koje polje Segment-a se menja ("roll")
#   step    korak u stepenima, max_deg do koliko stepeni
#   hold    koliko sekundi traje svaki korak
#   scale   stepeni -> komanda (10 deg * 0.005 = 0.05)
Axis = collections.namedtuple("Axis", "label field step max_deg hold scale")

AXES = {
    "roll":  Axis("ROLL",  "roll",  ROLL_STEP_DEG,  ROLL_MAX_DEG,  ROLL_HOLD_T,  ROLL_AMP_SCALE),
    "pitch": Axis("PITCH", "pitch", PITCH_STEP_DEG, PITCH_MAX_DEG, PITCH_HOLD_T, PITCH_AMP_SCALE),
    "yaw":   Axis("YAW",   "yaw",   YAW_STEP_DEG,   YAW_MAX_DEG,   YAW_HOLD_T,   YAW_AMP_SCALE),
}
DEF_AXES = "roll,pitch,yaw"

NUM_MOTORS = 4


# ============================================================================
# MIXER (X quad) - isti kao u droneCAN esc_control.py
# ============================================================================
def mix(T, R, P, Y):
    """Gas + roll/pitch/yaw -> komanda za 4 motora, svaka u MOTOR_IDLE..1."""
    m = (T + P + R - Y,
         T + P - R + Y,
         T - P - R - Y,
         T - P + R + Y)
    return [min(1.0, max(MOTOR_IDLE, v)) for v in m]


def to_pwm(m, args):
    """Komanda motora 0..1 -> PWM [us] u opsegu --min..--max."""
    return int(round(args.min + m * (args.max - args.min)))


def motor_pwms(link, args, m):
    """M1..Mn -> {esc_id: pwm}; motori bez ESC-a se preskacu."""
    return {esc: to_pwm(m[i], args) for i, esc in enumerate(link.escs)}


# ============================================================================
# SEKVENCA
# ============================================================================
# Jedna faza sekvence. T (gas) ide linearno od t_start do t_end tokom dur
# sekundi; roll/pitch/yaw su konstantni cele faze.
Segment = collections.namedtuple(
    "Segment", "name dur t_start t_end roll pitch yaw")

# Stanje sekvence u jednom trenutku (vraca ga Sequence.at).
#   idx  redni broj faze, seg  sama faza (Segment)
#   T R P Y  gas, roll, pitch, yaw u tom trenutku
SeqPoint = collections.namedtuple("SeqPoint", "idx seg T R P Y")


def add_segment(seq, name, dur, t_start, t_end=None,
                roll=0.0, pitch=0.0, yaw=0.0):
    """Doda fazu na kraj liste seq. t_end=None znaci da je gas konstantan.
    Faze trajanja 0 se preskacu."""
    if dur > 0:
        seq.append(Segment(name, float(dur), t_start,
                           t_start if t_end is None else t_end,
                           roll, pitch, yaw))


def add_axis_sweep(seq, axis, hover):
    """Koraci po jednoj osi, npr. za roll:
    ROLL +10, ROLL -10, HOVER, ROLL +20, ROLL -20, HOVER, ... do max_deg,
    pa duzi HOVER na kraju ose."""
    a = AXES[axis]
    deg = a.step
    # "+ step/2" da float greska ne preskoci poslednji korak (max_deg)
    while deg <= a.max_deg + a.step * 0.5 - 1e-9:
        amp = deg * a.scale
        add_segment(seq, f"{a.label} +{deg:g}deg", a.hold, hover, **{a.field: +amp})
        add_segment(seq, f"{a.label} -{deg:g}deg", a.hold, hover, **{a.field: -amp})
        add_segment(seq, "HOVER", STEP_GAP_T, hover)
        deg += a.step
    add_segment(seq, "HOVER", SWEEP_TAIL_T + BETWEEN_PAUSE, hover)


def build_sequence(args):
    """Cela sekvenca kao lista Segment-a, redom kako se izvrsavaju."""
    hover = args.hover
    seq = []

    # start: nule, rampa gasa do hover-a, zadrzavanje
    add_segment(seq, "ZERO", ZERO_SEQ_ON_START, 0.0)
    add_segment(seq, "THROTTLE RAMP", THROTTLE_RAMP_T, THROTTLE_MIN, hover)
    add_segment(seq, "THROTTLE DWELL", THROTTLE_DWELL_T, hover)
    add_segment(seq, "HOVER", BETWEEN_PAUSE, hover)

    # koraci po osama, redom iz --axes
    for axis in args.axes:
        add_axis_sweep(seq, axis, hover)

    # kraj: rampa gasa nadole i zadrzavanje na minimumu
    add_segment(seq, "THROTTLE RAMP DOWN", THROTTLE_RAMP_DOWN_T, hover, THROTTLE_MIN)
    add_segment(seq, "THROTTLE DWELL DOWN", THROTTLE_DWELL_DOWN_T, THROTTLE_MIN)
    return seq


class Sequence:
    """Lista faza + kad koja pocinje. at(t) kaze sta treba slati u trenutku t."""

    def __init__(self, segments):
        self.segments = segments
        self.starts = []          # starts[i] = sekunda u kojoj pocinje faza i
        t = 0.0
        for s in segments:
            self.starts.append(t)
            t += s.dur
        self.total = t            # trajanje cele sekvence [s]

    def at(self, t):
        """SeqPoint u trenutku t [s] od pocetka; None kad se sekvenca zavrsi."""
        if t >= self.total:
            return None
        i = bisect.bisect_right(self.starts, t) - 1     # poslednja faza koja je pocela
        s = self.segments[i]
        k = (t - self.starts[i]) / s.dur                # koliko smo odmakli u fazi, 0..1
        T = s.t_start + (s.t_end - s.t_start) * k       # gas: linearno t_start -> t_end
        return SeqPoint(i, s, T, s.roll, s.pitch, s.yaw)


# ============================================================================
# ISPIS
# ============================================================================
def motor_map_text(escs):
    """"M1=ESC2  M2=ESC3  M3=ESC4  M4=ESC5"."""
    return "  ".join(f"M{i + 1}=ESC{escs[i]}" if i < len(escs) else f"M{i + 1}=--"
                     for i in range(NUM_MOTORS))


def print_plan(seq, args):
    """Tabela svih faza (--plan): kad pocinje, koliko traje, T/R/P/Y i PWM."""
    print(f"motori: {motor_map_text(args.escs)}   PWM {args.min}..{args.max}"
          f"   hover {args.hover:g}")
    print(f"{'start':>7} {'dur':>5}  {'faza':<20} {'T':>11} {'R':>7} {'P':>7}"
          f" {'Y':>7}   PWM M1..M{NUM_MOTORS} (na kraju faze)")
    for start, s in zip(seq.starts, seq.segments):
        T = (f"{s.t_start:.3f}" if s.t_start == s.t_end
             else f"{s.t_start:.2f}->{s.t_end:.2f}")
        pwm = " ".join(f"{to_pwm(m, args):4d}"
                       for m in mix(s.t_end, s.roll, s.pitch, s.yaw))
        print(f"{start:7.1f} {s.dur:5.1f}  {s.name:<20} {T:>11} {s.roll:+7.3f}"
              f" {s.pitch:+7.3f} {s.yaw:+7.3f}   {pwm}")
    print(f"ukupno {seq.total:.1f}s (+ {'0' if args.no_arm else '~7'}s arm"
          f" i 1s gasenje)")


def announce_phase(view, t, p, pwms):
    """Stalan red u terminalu kad pocne nova faza."""
    pwm_txt = " ".join(f"{esc}:{pwm}" for esc, pwm in pwms.items())
    view.message(f"[{t:6.1f}s] {p.seg.name:<20} T={p.T:.3f} R={p.R:+.3f}"
                 f" P={p.P:+.3f} Y={p.Y:+.3f}  PWM {pwm_txt}")


def motors_text(link, m, pwms):
    """"M1 0.600 ESC2 1580  M2 ...  M4 0.600 ESC5 1580"."""
    parts = []
    for i in range(NUM_MOTORS):
        txt = f"M{i + 1} {m[i]:.3f}"
        if i < len(link.escs):
            esc = link.escs[i]
            txt += f" ESC{esc} {pwms[esc]}"
        else:
            txt += " --"
        parts.append(txt)
    return "  ".join(parts)


def sequence_status_lines(link, args, seq, t, p, m, pwms, now):
    """Status blok: faza i napredak, T/R/P/Y i motori, pa red po ESC-u i ADC."""
    head = (f"{p.seg.name:<20} {t:6.1f}/{seq.total:.0f}s"
            f" [{bar_text(t / seq.total)}]"
            f" {armed_text(link):8s} link:{link_state_text(link, now):10s}"
            f" fwd:{fwd_state_text(link)}")
    values = (f"  T {p.T:.3f} R {p.R:+.3f} P {p.P:+.3f} Y {p.Y:+.3f}"
              f" | {motors_text(link, m, pwms)}")
    return [head, values] + device_lines(link, now)


# ============================================================================
# ARGUMENTI
# ============================================================================
def parse_args():
    p = argparse.ArgumentParser(
        description="KDE ESC test sekvenca (roll/pitch/yaw koraci) preko MAVLink UDP-a")
    p.add_argument("--escs", default=",".join(str(e) for e in DEF_ESC_IDS),
                   help="ESC ID-jevi za M1,M2,M3[,M4] redom")
    p.add_argument("--hover", type=float, default=THROTTLE_HOVER,
                   help="hover gas 0..1 (rampa ide do njega)")
    p.add_argument("--axes", default=DEF_AXES,
                   help="ose i redosled, npr. roll,pitch,yaw ili yaw")
    p.add_argument("--plan", action="store_true",
                   help="samo ispisi sekvencu, nista ne salji")
    add_link_args(p)
    a = p.parse_args()

    a.escs = parse_id_list(p, a.escs, "ESC-ova")
    if len(a.escs) > NUM_MOTORS:
        p.error(f"najvise {NUM_MOTORS} ESC-a (M1..M{NUM_MOTORS})")

    a.axes = [x for x in a.axes.replace(" ", "").lower().split(",") if x]
    bad = [x for x in a.axes if x not in AXES]
    if bad or not a.axes:
        p.error(f"--axes: nepoznato {bad}, dozvoljeno {','.join(AXES)}")

    if not 0.0 < a.hover <= 1.0:
        p.error("--hover mora biti u (0, 1]")

    check_link_args(p, a)
    return a


# ============================================================================
# PETLJA SEKVENCE
# ============================================================================
def check_abort_keys(keyboard):
    """q / x / space / Ctrl+C -> prekid (KeyboardInterrupt, main gasi motore)."""
    for c in keyboard.pressed():
        if c in ("q", "x", " ", "\x03"):
            raise KeyboardInterrupt


def send_next_setpoint(link, p, pwms):
    """PWM sledecem ESC-u po redu. Kad krug zavrsi (svi ESC-ovi dobili po
    jedan), upise u setpoint/ fazu, T/R/P/Y i PWM-ove."""
    round_done = link.set_next_esc(pwms)
    if round_done and link.logger:
        link.logger.log_command(p.seg.name, pwms, (p.T, p.R, p.P, p.Y))


def run_sequence(link, args, seq, keyboard, stop):
    """Pusta sekvencu od pocetka. Vraca True ako je stigla do kraja, False
    ako ju je prekinuo SIGTERM / SIGHUP (stop["flag"]). Taster za prekid
    dize KeyboardInterrupt."""
    view = StatusView()
    t0 = time.monotonic()
    sender = Ticker(1.0 / (args.rate * len(link.escs)), start=t0)
    next_print = 0.0
    last_idx = -1

    while not stop["flag"]:
        now = time.monotonic()
        link.poll_rx()
        check_abort_keys(keyboard)

        # gde smo u sekvenci
        t = now - t0
        p = seq.at(t)
        if p is None:
            return True                      # sekvenca zavrsena

        # T,R,P,Y -> motori 0..1 -> PWM po ESC-u
        m = mix(p.T, p.R, p.P, p.Y)
        pwms = motor_pwms(link, args, m)

        if p.idx != last_idx:                # pocela je nova faza
            last_idx = p.idx
            announce_phase(view, t, p, pwms)

        if sender.due(now):
            send_next_setpoint(link, p, pwms)

        if now >= next_print:
            next_print = now + PRINT_PERIOD_S
            view.draw(sequence_status_lines(link, args, seq, t, p, m, pwms, now))

        sleep_until(link, min(sender.next_t, next_print))

    return False


# ============================================================================
# MAIN
# ============================================================================
def main():
    args = parse_args()
    seq = Sequence(build_sequence(args))

    if args.plan:
        print_plan(seq, args)
        return

    link = EscLink(args)
    print(f"motori: {motor_map_text(link.escs)}   sekvenca {seq.total:.1f}s")
    open_outputs(args, link, "esc_test")

    stop = install_stop_signals()
    keyboard = Keyboard()
    result = "PREKINUTO"

    try:
        keyboard.start()
        arm_fleet(link, args)
        if run_sequence(link, args, seq, keyboard, stop):
            result = "ZAVRSENO"
    except KeyboardInterrupt:
        pass
    finally:
        # ovo se izvrsava UVEK - i na kraju sekvence, i na prekid, i na gresku
        keyboard.restore()
        print(f"\n[{result}] minimum")
        shutdown(link, args)
        link.close()


if __name__ == "__main__":
    main()
