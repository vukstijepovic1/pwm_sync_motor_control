#!/usr/bin/env python3
"""
esc_control.py - interaktivna kontrola KDE ESC-ova preko MAVLink-a (UDP).

Tastatura:
    w / s     +/- STEP_PWM
    W / S     +/- 5*STEP_PWM
    space     PWM na minimum (idle)
    a         ponovo posalji ARM
    d         posalji DISARM (skripta nastavlja da radi)
    r         reset zastite od niskog napona (posle nje PWM ostaje minimum)
    x         emergency: minimum + izlaz
    q         izlaz (minimum, bez DISARM-a)
    Ctrl+C    isto kao q

Koriscenje:
    python3 esc_control.py
    python3 esc_control.py --escs 2,3,4,5 --rate 200 --force
    python3 esc_control.py --ip 192.168.1.104 --port 1004 --step 20
    python3 esc_control.py --fwd-ip 192.168.1.160 --fwd-port 1024
    python3 esc_control.py --no-fwd --no-log
    python3 esc_control.py --cutoff-v 0          bez zastite od niskog napona

===========================================================================
TOK PROGRAMA (main)
===========================================================================
    1. parse_args()        procita argumente komandne linije
    2. EscLink(args)       otvori UDP socket ka ploci
    3. open_outputs()      otvori .h5 log i prosledjivanje telemetrije
    4. arm_fleet()         posalje ARM i ceka ARM_HOLD_S (~6s) dok ploca
                           armuje ESC-ove
    5. run_manual_loop()   glavna petlja, vrti se svakih par ms:
          a) link.poll_rx()       primi sve sa ploce (telemetrija, ACK, HB)
          b) handle_key()         taster -> promeni zeljeni PWM / ARM / DISARM
          c) send_tick()          posalji PWM SLEDECEM ESC-u (round-robin)
          d) view.draw()          osvezi ekran (10 puta u sekundi)
    6. shutdown()          minimum PWM 1s, bez DISARM-a - uvek, i kad se
                           prekine sa q / Ctrl+C / kill

===========================================================================
DELOVI FAJLA (redom)
===========================================================================
    KONSTANTE           IP, portovi, PWM opseg, ID-jevi MAVLink poruka
    MAVLINK             pravljenje paketa (MavlinkV2) i citanje
                        (iter_mav_frames) - bez eksternih biblioteka
    LINK KA PLOCI       EscLink - slanje komandi i prijem telemetrije
    LOG I FWD           H5Table, EscLogger (jedan .h5 fajl),
                        TelemetryForwarder (UDP na drugi uredjaj)
    EKRAN               tekst status ekrana (esc_line, adc_line, StatusView)
    ZAJEDNICKO          Ticker, Keyboard, arm_fleet, shutdown, argumenti...
                        (ovo koristi i esc_test.py)
    RUCNA KONTROLA      ManualState, handle_key, run_manual_loop, main

===========================================================================
DETALJI
===========================================================================
Sta se salje na plocu:
    COMMAND_LONG / MAV_CMD_DO_SET_SERVO       (183) -> kde_set_pwm() po ESC-u
    COMMAND_LONG / MAV_CMD_COMPONENT_ARM_DISARM (400) -> kde_arm_all()

Sta se prima (ako ploca salje):
    COMMAND_ACK (77) -> stvarno znamo da li je komanda prihvacena
    HEARTBEAT   (0)  -> base_mode & MAV_MODE_FLAG_SAFETY_ARMED
    ESC_STATUS  (291) -> 4 napona sa AD7705 (2 ADC-a x 2 kanala), 10 Hz

Zastita od niskog napona (--cutoff-v, podrazumevano 42 V, 0 = iskljucena):
    cim bilo koji ESC javi napon ispod granice, svim ESC-ovima odmah ide
    minimum, ne ceka se round-robin. Posle toga EscLink.set_servo salje samo
    minimum dok se ne pritisne r (esc_control.py); esc_test.py prekida
    sekvencu. U logu je to faza LOW_V.
"""

import argparse
import collections
import datetime
import os
import select
import signal
import socket
import struct
import sys
import termios
import time
import tty

# ===========================================================================
# KONSTANTE
# ===========================================================================

# ---- adrese ----------------------------------------------------------------
DEF_BOARD_IP   = "192.168.1.104"
DEF_BOARD_PORT = 1004
DEF_LOCAL_PORT = 1004

SRC_SYSID  = 0     # client_mav_sysid
SRC_COMPID = 76    # MAV_COMP_ID_USER52 (client_mav_compid)
DST_SYSID  = 0     # broadcast
DST_COMPID = 0

# ---- ESC-ovi i PWM -----------------------------------------------------------
DEF_ESC_IDS     = [2, 3, 4, 5]   # esc_fleet[] iz task_bridge.c 
KDE_MIN_PWM     = 1100          
KDE_MAX_PWM     = 2000          
DEF_STEP_PWM    = 10
DEF_ESC_RATE_HZ = 100            # po ESC-u 
DEF_CUTOFF_V    = 42.0           # ESC javi napon ispod ovoga -> svi motori na minimum

# ---- vremena -----------------------------------------------------------------
# kde_arm_all() blokira ~5s (RESTART + 2s settle + 3s idle). Cekamo fiksno malo
# duze - ACK ne skracuje cekanje.
ARM_HOLD_S   = 6.0
SETTLE_S     = 1.0    # posle arma drzimo minimum pre nego sto dozvolimo gas
SHUTDOWN_S   = 1.0    # koliko dugo saljemo minimum pre izlaza

BOARD_HB_TIMEOUT_S = 3.0   # posle ovoliko bez heartbeat-a sa ploce -> upozorenje
ESC_TEL_STALE_S    = 1.0   # telemetrija starija od ovoga se prikazuje kao "--"

PRINT_PERIOD_S = 0.1       # ekran se osvezava 10 puta u sekundi
MAX_SLEEP_S    = 0.02      # petlja nikad ne spava duze od ovoga

# ---- prosledjivanje telemetrije na drugi uredjaj (kao udp_decode.py) -------
DEF_FWD_IP       = "192.168.1.160"
DEF_FWD_PORT     = 1024
DEF_FWD_RATE_HZ  = 50.0      # KDE BASE_STAT stize ~3 Hz po ESC-u, 10 Hz je dovoljno
FWD_SLOTS        = 4         # NUM_MOTORS iz udp_decode.py
FWD_SETPOINT_FULL = 8191.0   # DroneCAN RawCommand pun gas
KELVIN           = 273.15    # DroneCAN esc.Status nosi temperaturu u K

# ---- log -----------------------------------------------------------------------
DEF_LOG_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "logs")
H5_FLUSH_S  = 1.0            # HDF5 se dopisuje u paketima, ne red po red

# ---- MAVLink komande -------------------------------------------------------------
MAV_CMD_DO_SET_SERVO         = 183
MAV_CMD_COMPONENT_ARM_DISARM = 400
ARM_MAGIC_FORCE              = 21196   # preskace preflight checkove

# ---- MAVLink poruke koje primamo ---------------------------------------------------
MSG_HEARTBEAT         = 0
MSG_COMMAND_LONG      = 76
MSG_COMMAND_ACK       = 77
MSG_NAMED_VALUE_INT   = 252     # "in<id>"/"out<id>"/"warn<id>" posle svakog ESC_STATUS
MSG_ESC_STATUS        = 291     # task_work: naponi sa AD7705 u voltage[0..3]
MSG_LISUM_ESC_STATUS  = 59520   # task_mav salje posle arma (GET_BASE_STAT po ESC-u)

# BASE_STAT warning bajt, bitovi po kde_warning_type_e iz kde.h
KDE_WARN_BITS = {
    0: "STALL",
    1: "OVER_TEMP",
    2: "OVERLOAD",
    3: "OVER_V",
    4: "LOW_V",
    5: "V_CUTOFF",
}

# ESC_STATUS voltage[i] -> kanal, i = adc * 2 + kanal (task_work.c)
ADC_CHANNEL_NAMES = ("ADC1 CH0", "ADC1 CH1", "ADC2 CH0", "ADC2 CH1")

MAV_MODE_FLAG_SAFETY_ARMED = 128

MAVLINK_STX_V2 = 0xFD     # prvi bajt MAVLink v2 paketa
MAVLINK_STX_V1 = 0xFE     # prvi bajt MAVLink v1 paketa

# crc_extra iz common.xml - svaka poruka ima svoj, ulazi u CRC
CRC_EXTRA = {
    0:  50,    # HEARTBEAT
    76: 152,   # COMMAND_LONG
    77: 143,   # COMMAND_ACK
    252: 44,   # NAMED_VALUE_INT
    291: 10,   # ESC_STATUS
    59520: 44, # LISUM_ESC_STATUS
}

MAV_RESULT = {
    0: "ACCEPTED",
    1: "TEMPORARILY_REJECTED",
    2: "DENIED",
    3: "UNSUPPORTED",
    4: "FAILED",
    5: "IN_PROGRESS",
    6: "CANCELLED",
}


# ===========================================================================
# MAVLINK - pakovanje i raspakivanje, bez eksternih zavisnosti
# ===========================================================================
#
# Izgled MAVLink v2 paketa (bajtovi):
#
#   [0]      STX = 0xFD
#   [1]      duzina payload-a
#   [2]      incompat_flags (bit 0 = paket je potpisan)
#   [3]      compat_flags
#   [4]      seq (redni broj, 0..255)
#   [5]      sysid posiljaoca
#   [6]      compid posiljaoca
#   [7..9]   msgid (3 bajta, little-endian)
#   [10..]   payload
#   +2       CRC (x25 preko bajtova [1..kraj payload-a] + crc_extra poruke)
#   +13      potpis (samo ako je bit 0 u incompat_flags)
#
# MAVLink v1 je isti princip, samo kraci header (6 bajtova) i msgid 1 bajt.

def x25_crc(data, crc=0xFFFF):
    """CRC-16 koji MAVLink koristi (X.25 / MCRF4XX)."""
    for b in data:
        tmp = (b ^ (crc & 0xFF)) & 0xFF
        tmp = (tmp ^ (tmp << 4)) & 0xFF
        crc = ((crc >> 8) ^ (tmp << 8) ^ (tmp << 3) ^ (tmp >> 4)) & 0xFFFF
    return crc


def mavlink_crc(header_and_payload, msgid):
    """CRC MAVLink paketa: x25 preko header-a (bez STX) i payload-a, pa jos
    preko crc_extra bajta te poruke."""
    crc = x25_crc(header_and_payload)
    return x25_crc(bytes([CRC_EXTRA[msgid]]), crc)


def unpack_padded(fmt, payload):
    """MAVLink v2 sme da odsece nule sa kraja - dopunimo pre unpack-a."""
    need = struct.calcsize(fmt)
    if len(payload) < need:
        payload = payload + b"\x00" * (need - len(payload))
    return struct.unpack(fmt, payload[:need])


def truncate_trailing_zeros(payload):
    """MAVLink v2 truncate: odseci nule sa kraja payload-a (bar 1 bajt ostaje)."""
    plen = len(payload)
    while plen > 1 and payload[plen - 1] == 0:
        plen -= 1
    return payload[:plen]


class MavlinkV2:
    """Pravi MAVLink v2 pakete koje saljemo ploci."""

    def __init__(self, sysid, compid, truncate=False):
        self.sysid = sysid
        self.compid = compid
        self.truncate = truncate
        self.seq = 0

    def pack(self, msgid, payload):
        """Ceo paket: STX + header + payload + CRC."""
        if self.truncate:
            payload = truncate_trailing_zeros(payload)

        header = struct.pack(
            "<BBBBBB",
            len(payload),   # duzina payload-a
            0,              # incompat_flags (bez potpisa)
            0,              # compat_flags
            self.seq,       # redni broj paketa
            self.sysid,
            self.compid,
        ) + struct.pack("<I", msgid)[:3]     # msgid zauzima 3 bajta

        crc = mavlink_crc(header + payload, msgid)

        self.seq = (self.seq + 1) & 0xFF
        return bytes([MAVLINK_STX_V2]) + header + payload + struct.pack("<H", crc)

    def command_long(self, target_sys, target_comp, command,
                     p1=0.0, p2=0.0, p3=0.0, p4=0.0, p5=0.0, p6=0.0, p7=0.0,
                     confirmation=0):
        """COMMAND_LONG paket: komanda + 7 float parametara."""
        payload = struct.pack(
            "<7fHBBB", p1, p2, p3, p4, p5, p6, p7,
            command, target_sys, target_comp, confirmation
        )
        return self.pack(MSG_COMMAND_LONG, payload)


def iter_mav_frames(data):
    """Izvlaci (msgid, sysid, compid, payload) iz jednog UDP datagrama.
    Podrzava i v1 i v2, CRC se proverava samo za poruke koje poznajemo.

    Ide bajt po bajt i trazi pocetak paketa (STX). Kad ga nadje, procita
    ceo paket i skoci iza njega. Ako paket nije ceo (datagram se zavrsio
    pre kraja paketa), staje."""
    i, n = 0, len(data)
    while i < n:
        stx = data[i]

        if stx == MAVLINK_STX_V2:
            frame, size = _read_v2_frame(data, i)
        elif stx == MAVLINK_STX_V1:
            frame, size = _read_v1_frame(data, i)
        else:
            i += 1              # nije pocetak paketa, idi dalje
            continue

        if size == 0:
            return              # paket nije ceo - kraj datagrama
        if frame is None:
            i += 1              # los CRC - trazi sledeci STX odmah iza
            continue

        yield frame
        i += size


def _read_v2_frame(data, i):
    """Cita MAVLink v2 paket koji pocinje na data[i].

    Vraca (frame, size):
        frame = (msgid, sysid, compid, payload), ili None ako CRC ne valja
        size  = koliko bajtova paket zauzima, ili 0 ako paket nije ceo
    """
    n = len(data)
    if i + 12 > n:
        return None, 0
    plen     = data[i + 1]
    incompat = data[i + 2]
    sig_len  = 13 if (incompat & 0x01) else 0     # potpisan paket ima jos 13 bajtova
    size     = 12 + plen + sig_len
    if i + size > n:
        return None, 0

    sysid   = data[i + 5]
    compid  = data[i + 6]
    msgid   = int.from_bytes(data[i + 7:i + 10], "little")
    payload = data[i + 10:i + 10 + plen]
    crc_rx  = struct.unpack_from("<H", data, i + 10 + plen)[0]

    # CRC mozemo da proverimo samo za poruke ciji crc_extra znamo
    if msgid in CRC_EXTRA:
        if mavlink_crc(data[i + 1:i + 10 + plen], msgid) != crc_rx:
            return None, size

    return (msgid, sysid, compid, payload), size


def _read_v1_frame(data, i):
    """Cita MAVLink v1 paket koji pocinje na data[i] (CRC se ne proverava).
    Vraca (frame, size) isto kao _read_v2_frame."""
    n = len(data)
    if i + 8 > n:
        return None, 0
    plen = data[i + 1]
    size = 8 + plen
    if i + size > n:
        return None, 0

    sysid  = data[i + 3]
    compid = data[i + 4]
    msgid  = data[i + 5]
    return (msgid, sysid, compid, data[i + 6:i + 6 + plen]), size


# ===========================================================================
# LINK KA PLOCI
# ===========================================================================

# Sta pamtimo od svake poruke sa ploce. Poslednje polje (t) je uvek
# time.monotonic() u trenutku prijema - po njemu znamo da li je podatak svez.
KdeTelemetry = collections.namedtuple("KdeTelemetry", "volts amps rpm temp_c t")
AdcVoltages  = collections.namedtuple("AdcVoltages", "volts t")
NamedValue   = collections.namedtuple("NamedValue", "value t")
CommandAck   = collections.namedtuple("CommandAck", "command result t")
LowVoltage   = collections.namedtuple("LowVoltage", "esc volts t")


def fresh(entry, now):
    """entry ako je stigao pre manje od ESC_TEL_STALE_S, inace None."""
    if entry is None or now - entry.t > ESC_TEL_STALE_S:
        return None
    return entry


class EscLink:
    """Sve sto ide ka ploci i sa ploce.

    Slanje:   set_servo / set_next_esc / set_all   -> PWM za ESC
              arm_disarm                           -> ARM / DISARM
    Prijem:   poll_rx() - zove se u svakoj petlji. Primi sve pakete, zapamti
              poslednju telemetriju (esc_tel, named, adc), upise je u log i
              prosledi na drugi uredjaj.
    Zastita:  napon ESC-a ispod --cutoff-v -> low_v se postavi, svim
              ESC-ovima odmah minimum, i set_servo dalje salje samo minimum
              dok neko ne vrati low_v na None.
    Citanje:  sample(dev, now) - poslednja telemetrija jednog uredjaja kao
              dict; to koriste i log i prosledjivanje.
    """

    def __init__(self, args):
        self.args = args
        self.escs = args.escs
        self.dst = (args.ip, args.port)

        self.sock, self.rx_ok = self._open_socket(args.local_port)
        self.mav = MavlinkV2(SRC_SYSID, SRC_COMPID, truncate=args.truncate)

        # ---- stanje sa ploce (puni ga poll_rx) ----
        self.board_armed = None       # True / False iz HEARTBEAT-a, None = ne znamo
        self.last_board_hb = 0.0      # kad je stigao poslednji HEARTBEAT ploce
        self.last_ack = None          # CommandAck - poslednji ACK bilo koje komande
        self.arm_ack  = None          # result poslednjeg ACK-a na ARM/DISARM
        self.esc_tel  = {}            # esc_id  -> KdeTelemetry
        self.named    = {}            # "in2"   -> NamedValue
        self.adc      = None          # AdcVoltages - 4 napona sa AD7705
        self.low_v    = None          # LowVoltage kad je zastita okinula

        # ---- sta smo poslali ----
        self.setpoints = {}           # esc_id -> poslednji poslat PWM

        # zakace se iz open_outputs(); poll_rx() ih servisira
        self.logger = None
        self.fwd    = None

        self._esc_idx = 0             # koji ESC je sledeci na redu (set_next_esc)

    @staticmethod
    def _open_socket(local_port):
        """UDP socket koji ne blokira. Ako lokalni port nije slobodan, slanje
        i dalje radi, ali ne ocekujemo prijem (rx_ok = False)."""
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.setblocking(False)
        try:
            sock.bind(("0.0.0.0", local_port))
            rx_ok = True
        except OSError:
            rx_ok = False
        return sock, rx_ok

    # ---- slanje -----------------------------------------------------------
    def _send(self, frame):
        try:
            self.sock.sendto(frame, self.dst)
        except OSError as e:
            print(f"\nsend greska: {e}")

    def set_servo(self, esc, pwm):
        """Posalji jedan PWM [us] jednom ESC-u (MAV_CMD_DO_SET_SERVO).
        Dok je zastita od niskog napona okinula, salje se minimum."""
        if self.low_v is not None:
            pwm = self.args.min
        self._send(self.mav.command_long(
            DST_SYSID, DST_COMPID, MAV_CMD_DO_SET_SERVO,
            p1=float(esc), p2=float(pwm)))
        self.setpoints[esc] = pwm

    def set_next_esc(self, pwm):
        """Jedan ESC po pozivu, round-robin - da ne pretrpamo queue_comm.
        pwm je jedan broj za sve ESC-ove ili dict esc_id -> pwm.
        Vraca True kad je ovim pozivom zavrsen krug (svaki ESC dobio po jedan)."""
        esc = self.escs[self._esc_idx]
        self.set_servo(esc, pwm[esc] if isinstance(pwm, dict) else pwm)
        self._esc_idx = (self._esc_idx + 1) % len(self.escs)
        return self._esc_idx == 0

    def set_all(self, pwm, spacing_s=0.005):
        """Isti PWM svim ESC-ovima odjednom, sa malim razmakom izmedju paketa."""
        for esc in self.escs:
            self.set_servo(esc, pwm)
            if spacing_s:
                time.sleep(spacing_s)

    def arm_disarm(self, arm, force=False):
        """ARM (arm=True) ili DISARM (arm=False). force preskace preflight."""
        self.arm_ack = None
        self._send(self.mav.command_long(
            DST_SYSID, DST_COMPID, MAV_CMD_COMPONENT_ARM_DISARM,
            p1=1.0 if arm else 0.0,
            p2=float(ARM_MAGIC_FORCE) if force else 0.0))

    # ---- prijem -----------------------------------------------------------
    def poll_rx(self):
        """Prima sve sto je stiglo sa ploce, svaki novi uzorak ESC
        telemetrije upisuje u log, i (svojim rate-om) prosledjuje telemetriju
        na drugi uredjaj. Zove se u svakoj petlji, pa log i prosledjivanje
        rade i dok se armuje i dok se gasi."""
        self._receive_all()
        if self.fwd:
            self.fwd.tick(time.monotonic())

    def _receive_all(self):
        """Isprazni socket: obradi svaki paket koji je stigao od proslog puta."""
        while True:
            try:
                data, _ = self.sock.recvfrom(4096)
            except (BlockingIOError, OSError):
                return          # socket je prazan
            for msgid, sysid, compid, payload in iter_mav_frames(data):
                self._handle(msgid, sysid, compid, payload)

    def _handle(self, msgid, sysid, compid, payload):
        """Prosledi primljenu poruku odgovarajucem _on_* handler-u.
        Poruke koje ne znamo se ignorisu."""
        if msgid == MSG_HEARTBEAT:
            self._on_heartbeat(sysid, compid, payload)
        elif msgid == MSG_COMMAND_ACK:
            self._on_command_ack(payload)
        elif msgid == MSG_LISUM_ESC_STATUS:
            self._on_kde_status(payload)
        elif msgid == MSG_NAMED_VALUE_INT:
            self._on_named_value(payload)
        elif msgid == MSG_ESC_STATUS:
            self._on_adc_voltages(payload)

    def _on_heartbeat(self, sysid, compid, payload):
        """HEARTBEAT ploce -> da li je armovana i da li je link ziv."""
        if sysid == SRC_SYSID and compid == SRC_COMPID:
            return            # nas sopstveni heartbeat
        _, _, _, base_mode, _, _ = unpack_padded("<IBBBBB", payload)
        self.board_armed = bool(base_mode & MAV_MODE_FLAG_SAFETY_ARMED)
        self.last_board_hb = time.monotonic()

    def _on_command_ack(self, payload):
        """COMMAND_ACK -> da li je ploca prihvatila komandu."""
        cmd, result = unpack_padded("<HB", payload)[:2]
        self.last_ack = CommandAck(cmd, result, time.monotonic())
        if cmd == MAV_CMD_COMPONENT_ARM_DISARM:
            self.arm_ack = result

    def _on_kde_status(self, payload):
        """LISUM_ESC_STATUS - telemetrija jednog KDE ESC-a."""
        # 9 x float[2] pa uint8 index; task_mav puni samo [0], pa je
        # vrednost k-tog polja u f[2*k]
        f = unpack_padded("<18fB", payload)
        esc_id = f[18]
        self.esc_tel[esc_id] = KdeTelemetry(
            volts=f[0], amps=f[4], rpm=f[10], temp_c=f[8], t=time.monotonic())
        self._check_low_voltage(esc_id, f[0])
        self._log_sample(esc_id)

    def _check_low_voltage(self, esc, volts):
        """Zastita: ESC javi napon ispod --cutoff-v -> svim ESC-ovima odmah
        minimum, bez cekanja na sledeci krug round-robin-a."""
        if (self.low_v is not None or esc not in self.escs
                or not volts < self.args.cutoff_v):
            return
        self.low_v = LowVoltage(esc, volts, time.monotonic())
        for e in self.escs:
            self.set_servo(e, self.args.min)
        if self.logger:
            self.logger.log_command("LOW_V", {e: self.args.min for e in self.escs})

    def _on_named_value(self, payload):
        """NAMED_VALUE_INT "in<id>" / "out<id>" / "warn<id>"."""
        _, value, name = unpack_padded("<Ii10s", payload)
        name = name.split(b"\x00")[0].decode("ascii", "replace")
        self.named[name] = NamedValue(value, time.monotonic())

    def _on_adc_voltages(self, payload):
        """ESC_STATUS - 4 napona sa AD7705. task_work puni samo voltage[],
        rpm[] i current[] su nule."""
        # time_usec, rpm[4], voltage[4], current[4], index
        f = unpack_padded("<Q4i4f4fB", payload)
        volts = f[5:9]
        self.adc = AdcVoltages(volts, time.monotonic())
        if self.logger:
            self.logger.log_adc(volts)

    def _log_sample(self, dev):
        """Upisi trenutnu telemetriju uredjaja u log (ako log postoji)."""
        if self.logger:
            s = self.sample(dev, time.monotonic())
            if s is not None:
                self.logger.log_sample(dev, s)

    # ---- zajednicki pogled na telemetriju (log + prosledjivanje) ----------
    def throttle_pct(self, pwm):
        """PWM [us] -> gas [%] u opsegu --min..--max."""
        pct = (pwm - self.args.min) * 100.0 / (self.args.max - self.args.min)
        return max(0.0, min(100.0, pct))

    def setpoint_of(self, dev):
        """Poslednji PWM poslat ESC-u, None dok nista nije poslato."""
        return self.setpoints.get(dev)

    def named_value(self, name, now):
        """Vrednost NAMED_VALUE_INT-a (npr. "in2"), ili None ako je stara."""
        v = fresh(self.named.get(name), now)
        return None if v is None else v.value

    def sample(self, dev, now):
        """Poslednja telemetrija jednog ESC-a sa istim poljima kao stari
        udp_decode.py red (LISUM_ESC_STATUS + in/out/warn), ili None ako
        nema sveze. Vrednost koju ESC ne javlja je None."""
        t = fresh(self.esc_tel.get(dev), now)
        if t is None:
            return None
        pwm = self.setpoint_of(dev)
        return {
            "setpoint":    pwm,
            "voltage":     t.volts,
            "current":     t.amps,
            "temp_c":      t.temp_c,
            "rpm":         t.rpm,
            "power_pct":   None if pwm is None else self.throttle_pct(pwm),
            "error_count": self.named_value(f"warn{dev}", now),
            "pwm_in":      self.named_value(f"in{dev}", now),
            "pwm_out":     self.named_value(f"out{dev}", now),
        }

    def close(self):
        if self.fwd:
            self.fwd.close()
        if self.logger:
            self.logger.close()
        self.sock.close()


# ===========================================================================
# LOG I PROSLEDJIVANJE TELEMETRIJE NA DRUGI UREDJAJ
# ===========================================================================
class H5Table:
    """Tabela u jednoj grupi .h5 fajla: svaka kolona je 1-D dataset u grupi.
    Redovi se skupljaju i dopisuju svakih H5_FLUSH_S, a ostatak na flush()
    pri zatvaranju. dtype "str" je tekst promenljive duzine."""

    def __init__(self, group, cols):
        import h5py
        import numpy
        self._np = numpy
        self.group = group
        self.cols = cols
        for name, dtype in cols:
            if dtype == "str":
                dtype = h5py.string_dtype()
            group.create_dataset(name, shape=(0,), maxshape=(None,),
                                 dtype=dtype, chunks=(1024,),
                                 compression="gzip", compression_opts=4)
        self.rows = []
        self.next_flush = 0.0

    def append(self, row):
        """Dodaj red; na disk ide najvise jednom u H5_FLUSH_S."""
        self.rows.append(row)
        now = time.monotonic()
        if now >= self.next_flush:
            self.next_flush = now + H5_FLUSH_S
            self.flush()

    def flush(self):
        """Upisi sve skupljene redove: svaka kolona se produzi za n."""
        if not self.rows:
            return
        n = len(self.rows)
        columns = zip(*self.rows)            # redovi -> kolone
        for (name, _), col in zip(self.cols, columns):
            ds = self.group[name]
            ds.resize(ds.shape[0] + n, axis=0)
            ds[-n:] = self._np.asarray(col, dtype=ds.dtype)
        self.group.file.flush()
        self.rows.clear()


def _float_or_nan(v):
    return float("nan") if v is None else float(v)


def _int_or_minus1(v):
    return -1 if v is None else int(v)


def _power_byte(pct):
    """power_pct kolona je u1: zaokruzi i ogranici na 0..255; None -> 0."""
    if pct is None:
        return 0
    return max(0, min(255, int(round(pct))))


class EscLogger:
    """<tag>_<vreme>.h5 - jedno snimanje u jednom fajlu, tri tabele razlicite
    duzine, svaka u svojoj grupi (kolona je 1-D dataset, npr. f["esc/rpm"]).
    timestamp je u svim grupama time.time(), pa se tabele poravnaju po njemu.

    esc/
        Jedan red po uzorku telemetrije (~3 Hz po ESC-u). Kolone kao u
        starom udp_decode.py .h5, plus pwm_in / pwm_out. Razlike u znacenju:
          esc_index   - CAN ID (2,3,4,5), ne 0..3
          setpoint    - PWM [us] poslat tom ESC-u
          power_pct   - gas iz setpointa [%]
          rpm         - rpm motora
          error_count - KDE warn bajt (bitovi u KDE_WARN_BITS)
        Nepoznato je NaN (float) odnosno -1 (int).

    setpoint/
        Jedan red po krugu slanja: phase (tekst), T/R/P/Y (esc_test.py,
        inace NaN) i pwm_<id> po ESC-u.

    adc/
        Jedan red po ESC_STATUS-u (10 Hz): timestamp i 4 napona sa AD7705
        [V], kolone adc1_ch0, adc1_ch1, adc2_ch0, adc2_ch1.

    Stari esc_plot.py / esc_calibrate.py (droneCAN) citaju samo dataset-ove
    na vrhu fajla, pa ovaj format ne citaju - crta ga rpm_plot.py."""

    TEL_COLS = (
        ("timestamp",   "f8"),
        ("esc_index",   "u1"),
        ("setpoint",    "i2"),
        ("voltage",     "f4"),
        ("current",     "f4"),
        ("temp_c",      "f4"),
        ("rpm",         "f4"),
        ("power_pct",   "u1"),
        ("error_count", "i4"),
        ("pwm_in",      "i4"),
        ("pwm_out",     "i4"),
    )

    ADC_COLS = (("timestamp", "f8"),) + tuple(
        (n.lower().replace(" ", "_"), "f4") for n in ADC_CHANNEL_NAMES)

    def __init__(self, log_dir, tag, escs):
        import h5py  # bez h5py nema loga, open_outputs() to javlja

        os.makedirs(log_dir, exist_ok=True)
        stamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.path = os.path.join(log_dir, f"{tag}_{stamp}.h5")
        self.escs = list(escs)

        self.f = h5py.File(self.path, "w")
        self.f.attrs["created"] = stamp
        self.tel = H5Table(self.f.create_group("esc"), self.TEL_COLS)
        self.cmd = H5Table(self.f.create_group("setpoint"), self._cmd_cols())
        self.adc = H5Table(self.f.create_group("adc"), self.ADC_COLS)

    def _cmd_cols(self):
        """Kolone setpoint/: vreme, faza, T/R/P/Y, pa pwm_<id> po ESC-u."""
        return ((("timestamp", "f8"), ("phase", "str"),
                 ("T", "f4"), ("R", "f4"), ("P", "f4"), ("Y", "f4"))
                + tuple((f"pwm_{e}", "i2") for e in self.escs))

    def log_sample(self, dev, s):
        """Jedan red u esc/ iz dict-a koji vraca EscLink.sample()."""
        self.tel.append((
            time.time(),
            dev,
            _int_or_minus1(s["setpoint"]),
            _float_or_nan(s["voltage"]),
            _float_or_nan(s["current"]),
            _float_or_nan(s["temp_c"]),
            _float_or_nan(s["rpm"]),
            _power_byte(s["power_pct"]),
            _int_or_minus1(s["error_count"]),
            _int_or_minus1(s["pwm_in"]),
            _int_or_minus1(s["pwm_out"]),
        ))

    def log_command(self, phase, pwms, trpy=None):
        """Jedan red u setpoint/: faza, (T, R, P, Y) i PWM po ESC-u."""
        trpy = tuple(_float_or_nan(v) for v in (trpy or (None,) * 4))
        self.cmd.append((time.time(), phase) + trpy
                        + tuple(pwms.get(e, -1) for e in self.escs))

    def log_adc(self, volts):
        """Jedan red u adc/: 4 napona sa AD7705 [V]."""
        self.adc.append((time.time(),) + tuple(float(v) for v in volts))

    def close(self):
        self.tel.flush()
        self.cmd.flush()
        self.adc.flush()
        self.f.close()


class TelemetryForwarder:
    """Salje telemetriju na drugi uredjaj u istom formatu koji je
    udp_decode.py prosledjivao na 192.168.1.160:1024 (a DroneCAN ploca
    slala na port 2049): FWD_SLOTS blokova po 7 x float32 little-endian

        setpoint     DroneCAN RawCommand skala 0..8191 (iz PWM-a)
        power_pct    gas / duty [%]
        rpm          rpm motora
        voltage      [V]
        current      [A]
        temperature  [K]
        error_count  KDE warn bajt

    Slotovi su redom ESC-ovi iz --escs. Slot bez sveze telemetrije ide kao
    nule (samo setpoint je popunjen)."""

    def __init__(self, link, dst, rate_hz):
        self.link = link
        self.dst = dst
        self.ticker = Ticker(1.0 / rate_hz, start=0.0)
        self.slots = list(link.escs)[:FWD_SLOTS]
        self.slots += [None] * (FWD_SLOTS - len(self.slots))
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.error = None

    def tick(self, now):
        """Zove se iz poll_rx(); salje paket samo kad dodje red (--fwd-rate)."""
        if not self.ticker.due(now):
            return
        pkt = b"".join(self._block(dev, now) for dev in self.slots)
        try:
            self.sock.sendto(pkt, self.dst)
            self.error = None
        except OSError as e:
            self.error = str(e)

    def _block(self, dev, now):
        """7 float-ova za jedan slot (jedan uredjaj)."""
        if dev is None:                      # prazan slot
            return struct.pack("<7f", *([0.0] * 7))

        sp = self._setpoint_raw(dev)
        s = self.link.sample(dev, now)
        if s is None:                        # nema sveze telemetrije
            return struct.pack("<7f", sp, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

        def f(v):
            return 0.0 if v is None else float(v)

        temp_k = 0.0 if s["temp_c"] is None else s["temp_c"] + KELVIN
        return struct.pack("<7f", sp, f(s["power_pct"]), f(s["rpm"]),
                           f(s["voltage"]), f(s["current"]), temp_k,
                           f(s["error_count"]))

    def _setpoint_raw(self, dev):
        """Poslednji PWM uredjaja u DroneCAN RawCommand skali 0..8191."""
        pwm = self.link.setpoint_of(dev)
        if pwm is None:
            return 0.0
        return self.link.throttle_pct(pwm) / 100.0 * FWD_SETPOINT_FULL

    def close(self):
        self.sock.close()


def open_outputs(args, link, tag):
    """Zakaci log i prosledjivanje na link (po --no-log / --no-fwd)."""
    if not args.no_log:
        link.logger = _open_logger(args, link, tag)
    if not args.no_fwd:
        link.fwd = _open_forwarder(args, link)


def _open_logger(args, link, tag):
    try:
        logger = EscLogger(args.log_dir, tag, link.escs)
    except ImportError:
        link.close()
        sys.exit("log se pise u .h5 - instaliraj h5py (pip install h5py)"
                 " ili pokreni sa --no-log")
    print(f"log: {logger.path}")
    return logger


def _open_forwarder(args, link):
    fwd = TelemetryForwarder(link, (args.fwd_ip, args.fwd_port), args.fwd_rate)
    slots = ",".join("-" if d is None else str(d) for d in fwd.slots)
    print(f"fwd: {args.fwd_ip}:{args.fwd_port} @ {args.fwd_rate:g} Hz,"
          f" slotovi {slots}")
    return fwd


# ===========================================================================
# EKRAN - tekst koji se ispisuje u terminalu
# ===========================================================================
def ack_text(link):
    if link.arm_ack is None:
        return "bez ACK-a"
    return MAV_RESULT.get(link.arm_ack, f"result={link.arm_ack}")


def armed_text(link):
    if link.board_armed is None:
        return "?"
    return "ARMED" if link.board_armed else "DISARMED"


def link_state_text(link, now):
    """"ok" ako ploca salje HEARTBEAT, "NEMA HB" ako je prestala, "-" ako
    nikad nije poslala."""
    hb_age = now - link.last_board_hb if link.last_board_hb else None
    if link.rx_ok and hb_age is not None and hb_age > BOARD_HB_TIMEOUT_S:
        return f"NEMA HB {hb_age:.0f}s"
    if hb_age is not None:
        return "ok"
    return "-"


def fwd_state_text(link):
    if link.fwd is None:
        return "off"
    return "ok" if link.fwd.error is None else "GRESKA"


def warn_text(w):
    """KDE warn bajt -> tekst, npr. "0x03 STALL,OVER_TEMP"."""
    if w is None:
        return "--"
    if w == 0:
        return "0"
    names = [n for bit, n in KDE_WARN_BITS.items() if w & (1 << bit)]
    return f"0x{w:02x} " + ",".join(names)


def bar_text(fraction, width=30):
    """Traka napretka, npr. "#####........" za fraction 0..1."""
    n = int(fraction * width)
    return "#" * n + "." * (width - n)


def esc_line(link, esc, now):
    """Jedan red po ESC-u. "--" = ESC na to ne odgovara na CAN.
    pwm_in/pwm_out su sirove vrednosti objekata 6/7 - ono sto ESC sam vidi
    na ulazu gasa i sta daje na izlaz."""
    t = fresh(link.esc_tel.get(esc), now)
    if t is None:
        base = f"{'--':>5} V {'--':>5} A {'--':>6} rpm"
    else:
        base = f"{t.volts:5.1f} V {t.amps:5.1f} A {t.rpm:6.0f} rpm"

    p_in  = link.named_value(f"in{esc}", now)
    p_out = link.named_value(f"out{esc}", now)
    warn  = link.named_value(f"warn{esc}", now)
    p_in  = "--" if p_in is None else str(p_in)
    p_out = "--" if p_out is None else str(p_out)

    return (f"  ESC {esc}: {base} | pwm_in {p_in:>5} pwm_out {p_out:>5}"
            f" | warn {warn_text(warn)}")


def adc_line(link, now):
    """Red sa 4 napona sa AD7705 (ESC_STATUS iz task_work) - napon direktno
    na bateriji, ne ono sto javljaju ESC-ovi. "--" = ploca ih ne salje
    (oba ADC-a pala na init-u) ili su stari."""
    a = fresh(link.adc, now)
    vals = (f"{v:6.2f}" for v in a.volts) if a else [f"{'--':>6}"] * 4
    return "  " + " | ".join(f"{n} {v} V"
                             for n, v in zip(ADC_CHANNEL_NAMES, vals))


def low_v_line(link):
    """Red zastite od niskog napona."""
    cutoff = link.args.cutoff_v
    lv = link.low_v
    if lv is not None:
        return (f"  !!! NIZAK NAPON: ESC {lv.esc} javio {lv.volts:.1f} V"
                f" < {cutoff:g} V - svi motori na minimumu")
    if cutoff <= 0:
        return "  zastita napona: iskljucena"
    return f"  zastita napona: ispod {cutoff:g} V svi motori na minimum"


def device_lines(link, now):
    """Po jedan red za svaki ESC, jedan za ADC napone i jedan za zastitu."""
    return ([esc_line(link, esc, now) for esc in link.escs]
            + [adc_line(link, now), low_v_line(link)])


class StatusView:
    """Crta blok od vise redova uvek na istom mestu (ANSI), da se dugacak
    red ne prelama i ne ponavlja u terminalu."""

    def __init__(self):
        self.lines = 0          # koliko redova je imao prethodno nacrtan blok

    def _back_to_block_start(self):
        """ANSI kod koji vraca kursor na pocetak prethodno nacrtanog bloka."""
        if self.lines > 1:
            return f"\x1b[{self.lines - 1}F"   # gore na pocetak prvog reda bloka
        if self.lines == 1:
            return "\r"
        return ""

    def draw(self, lines):
        """Precrtaj blok novim redovima ("\\x1b[2K" brise stari red)."""
        out = self._back_to_block_start()
        out += "\n".join("\x1b[2K" + l for l in lines)
        self.lines = len(lines)
        sys.stdout.write(out)
        sys.stdout.flush()

    def message(self, text):
        """Stalan red (npr. promena faze) na mestu bloka; sledeci draw()
        crta blok ispod njega, pa poruke ostaju u terminalu."""
        out = self._back_to_block_start()
        sys.stdout.write(out + "\x1b[2K" + text + "\n")
        sys.stdout.flush()
        self.lines = 0


# ===========================================================================
# ZAJEDNICKO za esc_control.py i esc_test.py
# ===========================================================================
class Ticker:
    """Periodican dogadjaj (slanje PWM-a, prosledjivanje telemetrije...).

    due(now) vraca True kad je doslo vreme i pomera rok za jedan period.
    Ako smo zaostali vise od jednog perioda (npr. petlja je zakocila), ne
    pokusava da nadoknadi propusteno, nego krece ispocetka od sada."""

    def __init__(self, period, start):
        self.period = period
        self.next_t = start

    def due(self, now):
        if now < self.next_t:
            return False
        self.next_t += self.period
        if self.next_t < now:          # zaostali smo, ne juri unazad
            self.next_t = now + self.period
        return True


class Keyboard:
    """Cita pojedinacne tastere bez Enter-a (cbreak mod terminala).
    Ako stdin nije terminal (npr. skripta pokrenuta iz druge skripte),
    tastatura se ignorise."""

    def __init__(self):
        self.is_tty = sys.stdin.isatty()
        self.fd = sys.stdin.fileno() if self.is_tty else None
        self.old_term = termios.tcgetattr(self.fd) if self.is_tty else None

    def start(self):
        """Terminal u cbreak: taster stize odmah, bez Enter-a."""
        if self.is_tty:
            tty.setcbreak(self.fd)

    def restore(self):
        """Vrati terminal kako je bio (mora na izlazu, inace terminal ostane cudan)."""
        if self.is_tty and self.old_term is not None:
            termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old_term)

    def pressed(self):
        """Svi tasteri pritisnuti od proslog poziva, jedan po jedan. Ne ceka."""
        if not self.is_tty:
            return
        while select.select([sys.stdin], [], [], 0)[0]:
            yield sys.stdin.read(1)


def install_stop_signals():
    """SIGTERM / SIGHUP (kill, zatvoren terminal) ne prekidaju skriptu na
    pola - samo postave stop["flag"], petlja izadje i motori se ugase
    normalno (minimum, bez DISARM-a)."""
    stop = {"flag": False}

    def on_signal(_sig, _frm):
        stop["flag"] = True

    signal.signal(signal.SIGTERM, on_signal)
    signal.signal(signal.SIGHUP, on_signal)
    return stop


def sleep_until(link, t_next):
    """Spava do t_next, ali najvise MAX_SLEEP_S, i probudi se ranije ako
    stigne paket sa ploce."""
    sleep_for = t_next - time.monotonic()
    if sleep_for <= 0:
        return
    if link.rx_ok:
        select.select([link.sock], [], [], min(sleep_for, MAX_SLEEP_S))
    else:
        time.sleep(min(sleep_for, MAX_SLEEP_S))


def wait_for_arm(link, hold_s):
    """Ceka fiksnih hold_s dok task_bridge radi kde_arm_all().
    NE salje gas, i NE prekida se na ACK / armed bit - kde_arm_all() svakako
    blokira ~3s, pa cekamo ceo interval. poll_rx samo belezi ACK za ispis."""
    t0 = time.monotonic()
    while True:
        now = time.monotonic()
        link.poll_rx()

        if now - t0 >= hold_s:
            return

        left = hold_s - (now - t0)
        sys.stdout.write(f"\rarmujem... jos {left:4.1f}s   ")
        sys.stdout.flush()
        time.sleep(0.05)


def arm_fleet(link, args):
    """Posalji ARM jednom i sacekaj da ploca zavrsi armovanje."""
    if args.no_arm:
        print("preskacem ARM (--no-arm)")
        return
    link.arm_disarm(True, force=args.force)
    wait_for_arm(link, ARM_HOLD_S)
    print(f"\rarm zavrsen ({ack_text(link)})" + " " * 20)


def shutdown(link, args):
    """Minimum SHUTDOWN_S sekundi, bez DISARM-a - ESC-ovi ostaju armovani na
    minimumu (DISARM samo rucno, taster d). Log i prosledjivanje rade do kraja."""
    send_min_pwm_for(link, args, SHUTDOWN_S)


def send_min_pwm_for(link, args, duration_s):
    """duration_s sekundi salje minimum PWM svim ESC-ovima (round-robin)."""
    tick_dt = 1.0 / (args.rate * len(link.escs))
    pwms = {esc: args.min for esc in link.escs}

    t_end = time.monotonic() + duration_s
    while time.monotonic() < t_end:
        link.poll_rx()
        if link.set_next_esc(args.min) and link.logger:
            link.logger.log_command("shutdown", pwms)
        time.sleep(tick_dt)


# ---- argumenti komandne linije ----------------------------------------------
def parse_id_list(p, text, what):
    """"2, 3,4" -> [2, 3, 4]."""
    ids = [int(x) for x in text.replace(" ", "").split(",") if x != ""]
    if not ids:
        p.error(f"prazna lista {what}")
    return ids


def add_link_args(p):
    """Argumenti zajednicki za esc_control.py i esc_test.py."""
    p.add_argument("--ip", default=DEF_BOARD_IP)
    p.add_argument("--port", type=int, default=DEF_BOARD_PORT)
    p.add_argument("--local-port", type=int, default=DEF_LOCAL_PORT)
    p.add_argument("--min", type=int, default=KDE_MIN_PWM)
    p.add_argument("--max", type=int, default=KDE_MAX_PWM)
    p.add_argument("--rate", type=float, default=DEF_ESC_RATE_HZ,
                   help="setpoint rate PO ESC-u (Hz)")
    p.add_argument("--force", action="store_true",
                   help="force arm (p2=21196, preskace preflight)")
    p.add_argument("--no-arm", action="store_true",
                   help="ne salji ARM (ako ploca vec drzi armovano)")
    p.add_argument("--cutoff-v", type=float, default=DEF_CUTOFF_V,
                   help="ESC javi napon ispod ovoga [V] -> svi motori odmah na "
                        f"minimum (podrazumevano {DEF_CUTOFF_V:g}, 0 = bez zastite)")
    p.add_argument("--truncate", action="store_true",
                   help="MAVLink v2 truncate nula na kraju payload-a")
    p.add_argument("--fwd-ip", default=DEF_FWD_IP,
                   help="uredjaj kome se prosledjuje telemetrija")
    p.add_argument("--fwd-port", type=int, default=DEF_FWD_PORT)
    p.add_argument("--fwd-rate", type=float, default=DEF_FWD_RATE_HZ,
                   help="koliko paketa u sekundi ide na --fwd-ip")
    p.add_argument("--no-fwd", action="store_true",
                   help="ne prosledjuj telemetriju")
    p.add_argument("--log-dir", default=DEF_LOG_DIR)
    p.add_argument("--no-log", action="store_true", help="bez log fajlova")


def check_link_args(p, a):
    if a.min >= a.max:
        p.error("--min mora biti manji od --max")
    if a.rate <= 0 or a.fwd_rate <= 0:
        p.error("--rate i --fwd-rate moraju biti > 0")
    if a.cutoff_v < 0:
        p.error("--cutoff-v mora biti >= 0")


def parse_args():
    p = argparse.ArgumentParser(description="KDE ESC kontrola preko MAVLink UDP-a")
    p.add_argument("--escs", default=",".join(str(e) for e in DEF_ESC_IDS),
                   help="lista ESC ID-jeva, npr. 2,3,4,5")
    p.add_argument("--step", type=int, default=DEF_STEP_PWM)
    add_link_args(p)
    a = p.parse_args()
    a.escs = parse_id_list(p, a.escs, "ESC-ova")
    check_link_args(p, a)
    return a


# ===========================================================================
# RUCNA KONTROLA (samo esc_control.py)
# ===========================================================================
class ManualState:
    """Sve sto se menja tokom rucne kontrole."""

    def __init__(self, args):
        self.pwm = args.min                              # zeljeni PWM za sve ESC-ove [us]
        self.settle_until = time.monotonic() + SETTLE_S  # do tada se drzi minimum
        self.note = ""                                   # poruka u status redu


def handle_key(c, state, link, args, now):
    """Jedan pritisnut taster. q / x / Ctrl+C dizu KeyboardInterrupt, a
    main() ga hvata i spusta motore na minimum (bez DISARM-a)."""
    if c == "w":
        state.pwm = min(args.max, state.pwm + args.step)
    elif c == "s":
        state.pwm = max(args.min, state.pwm - args.step)
    elif c == "W":
        state.pwm = min(args.max, state.pwm + 5 * args.step)
    elif c == "S":
        state.pwm = max(args.min, state.pwm - 5 * args.step)
    elif c == " ":
        state.pwm = args.min
    elif c == "a":
        state.pwm = args.min
        link.arm_disarm(True, force=args.force)
        state.note = "ARM poslat"
        state.settle_until = now + ARM_HOLD_S + SETTLE_S
    elif c == "d":
        state.pwm = args.min
        link.arm_disarm(False)
        state.note = "DISARM poslat"
    elif c == "r":
        state.pwm = args.min
        if link.low_v is not None:
            link.low_v = None       # ako je napon i dalje nizak, okine ponovo
            state.note = "zastita napona resetovana"
    elif c == "x":
        state.pwm = args.min
        raise KeyboardInterrupt
    elif c in ("q", "\x03"):
        raise KeyboardInterrupt


def send_tick(link, state, now):
    """PWM sledecem ESC-u po redu. Kad krug zavrsi (svi ESC-ovi dobili po
    jedan), upise u setpoint/ sta je poslato."""
    round_done = link.set_next_esc(state.pwm)
    if round_done and link.logger:
        if link.low_v is not None:
            phase = "LOW_V"
        elif now < state.settle_until:
            phase = "settle"
        else:
            phase = "manual"
        link.logger.log_command(
            phase, {esc: state.pwm for esc in link.escs},
            (link.throttle_pct(state.pwm) / 100.0, 0.0, 0.0, 0.0))


def manual_status_lines(link, args, state, now):
    """Status blok: PWM traka i stanje ploce, pa red po ESC-u i ADC."""
    fraction = (state.pwm - args.min) / (args.max - args.min)
    head = (f"PWM {state.pwm:4d} us [{bar_text(fraction)}] "
            f"{armed_text(link):8s} link:{link_state_text(link, now):10s} "
            f"fwd:{fwd_state_text(link)} {state.note}")
    return [head] + device_lines(link, now)


def run_manual_loop(link, args, keyboard, stop):
    """Glavna petlja. Radi dok se ne pritisne q / x / Ctrl+C
    (KeyboardInterrupt) ili ne stigne SIGTERM / SIGHUP (stop["flag"])."""
    state = ManualState(args)
    sender = Ticker(1.0 / (args.rate * len(args.escs)), start=time.monotonic())
    next_print = 0.0
    view = StatusView()

    while not stop["flag"]:
        now = time.monotonic()
        link.poll_rx()

        for c in keyboard.pressed():
            handle_key(c, state, link, args, now)

        # dok traje settle drzimo minimum
        if now < state.settle_until:
            state.pwm = args.min

        # zastita od niskog napona - minimum dok se ne pritisne r
        if link.low_v is not None:
            state.pwm = args.min
            state.note = "NIZAK NAPON - r = reset zastite"

        if sender.due(now):
            send_tick(link, state, now)

        if now >= next_print:
            next_print = now + PRINT_PERIOD_S
            view.draw(manual_status_lines(link, args, state, now))

        sleep_until(link, min(sender.next_t, next_print))


# ===========================================================================
# MAIN
# ===========================================================================
def main():
    args = parse_args()
    link = EscLink(args)
    open_outputs(args, link, "esc_control")

    stop = install_stop_signals()
    keyboard = Keyboard()

    try:
        keyboard.start()
        arm_fleet(link, args)
        run_manual_loop(link, args, keyboard, stop)
    except KeyboardInterrupt:
        pass
    finally:
        # ovo se izvrsava UVEK - i na q, i na Ctrl+C, i na gresku
        keyboard.restore()
        print("\nstop")
        shutdown(link, args)
        link.close()


if __name__ == "__main__":
    main()
