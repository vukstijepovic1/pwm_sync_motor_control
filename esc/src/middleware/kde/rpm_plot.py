#!/usr/bin/env python3
"""
rpm_plot.py - sve bitno iz jednog snimanja esc_control.py / esc_test.py, na
istoj vremenskoj osi (vreme od prvog uzorka u logu).

Koriscenje:
    python3 rpm_plot.py                          poslednji log iz logs/
    python3 rpm_plot.py 20261002_101837          log po vremenu (ili delu imena)
    python3 rpm_plot.py esc_test                 poslednji esc_test log
    python3 rpm_plot.py logs/esc_control_20261002_101837.h5
    python3 rpm_plot.py 101837 --out log.png     sacuvaj sliku umesto prozora
    python3 rpm_plot.py --current-from 600       struju crtaj od 600 s

Cita nov format (jedan <tag>_<vreme>.h5 sa grupama esc/, setpoint/, adc/) i
stari (tri fajla _esc.h5, _setpoint.h5, _adc.h5 - zadaje se bilo koji od njih
ili deo imena). Moze i dok esc_control.py jos pise isti log.

Grafici, odozgo nadole:
    PWM [us]        poslat setpoint po ESC-u (linija) i pwm_in - sta ESC sam
                    cita na ulazu gasa (tacke, ista boja)
    rpm             po ESC-u
    struja [A]
    napon [V]       sta javljaju ESC-ovi
    temperatura     ESC
    gas [%]         gas iz setpointa; pwm_out (objekat 7, sirovo) isprekidano
    ADC [V]         4 napona sa AD7705 (samo ako ih ima u logu)
    warn            KDE warn bajt (samo ako je negde != 0)
    T/R/P/Y         komanda iz esc_test.py (samo ako R/P/Y nisu sve nule)
Promene faze (settle, manual, ROLL +10deg, ...) su vertikalne linije.

Posebni prozori (uz --out slike <ime>_struja.png i <ime>_esc_adc.png):
    struja          samo struja, od 1200 s do kraja (--current-from)
    ESC - ADC [V]   napon koji javlja ESC minus njegov ADC kanal (ADC_OF_ESC),
                    samo ako ima ADC-a u logu
"""

import argparse
import glob
import os
import sys

# esc_control.py drzi log otvoren dok radi - bez ovoga h5py odbije da ga otvori
os.environ.setdefault("HDF5_USE_FILE_LOCKING", "FALSE")

import h5py
import matplotlib.pyplot as plt
import matplotlib.transforms as mtransforms
import numpy as np

from esc_control import DEF_LOG_DIR, KDE_WARN_BITS

CURRENT_FROM = 1200.0    # [s] odakle crta poseban prozor sa strujom

# koji AD7705 kanal meri isti napon kao ESC (CAN ID -> kolona u adc/)
ADC_OF_ESC = {2: "adc1_ch0", 3: "adc1_ch1", 4: "adc2_ch0", 5: "adc2_ch1"}

GROUPS = ("esc", "setpoint", "adc")
RUN_SUFFIXES = ("_esc.h5", "_setpoint.h5", "_adc.h5")   # stari format, redom kao GROUPS


# ---------------------------------------------------------------------------
# nalazenje i citanje loga
# ---------------------------------------------------------------------------
def old_run_base(path):
    """Stari format: putanja bez _esc.h5 / _setpoint.h5 / _adc.h5. Nov: None."""
    for suffix in RUN_SUFFIXES:
        if path.endswith(suffix):
            return path[:-len(suffix)]
    return None


def find_log(arg, log_dir):
    """Putanja do loga. arg je putanja, deo imena ili None (poslednji log)."""
    if arg and os.path.isfile(arg):
        return arg

    pattern = f"*{arg}*.h5" if arg else "*.h5"
    matches = sorted(glob.glob(os.path.join(log_dir, pattern)),
                     key=os.path.getmtime)
    if not matches:
        sys.exit(f"nema loga {pattern} u {log_dir}")

    runs = list(dict.fromkeys(old_run_base(m) or m for m in matches))
    if arg and len(runs) > 1:
        print(f"{len(runs)} logova odgovara '{arg}', crtam poslednji")
    return matches[-1]


def read_columns(group):
    """Sve kolone grupe (ili fajla) kao dict ime -> numpy niz. Dok
    esc_control.py pise, kolone mogu na trenutak biti razlicite duzine, pa se
    sve skrate na najkracu."""
    cols = {k: group[k][:] for k in group.keys()
            if isinstance(group[k], h5py.Dataset)}
    n = min((len(v) for v in cols.values()), default=0)
    return {k: v[:n] for k, v in cols.items()}


def load_run(path):
    """{"esc": {...}, "setpoint": {...}, "adc": {...}}; tabela koje nema je {}."""
    base = old_run_base(path)
    if base is None:
        with h5py.File(path, "r") as f:
            return {g: read_columns(f[g]) if g in f else {} for g in GROUPS}

    tables = {}
    for g, suffix in zip(GROUPS, RUN_SUFFIXES):
        if os.path.isfile(base + suffix):
            with h5py.File(base + suffix, "r") as f:
                tables[g] = read_columns(f)
        else:
            tables[g] = {}
    return tables


# ---------------------------------------------------------------------------
# podaci jednog snimanja
# ---------------------------------------------------------------------------
def as_float(a, missing=None):
    """float niz u kome je "nepoznato" NaN (int kolone loga koriste -1)."""
    a = np.asarray(a, dtype=float)
    if missing is not None:
        a[a == missing] = np.nan
    return a


def text_column(a):
    return [x.decode() if isinstance(x, bytes) else str(x) for x in a]


class Run:
    """Tri tabele jednog snimanja i zajednicko vreme t [s] od prvog uzorka."""

    def __init__(self, tables):
        self.esc, self.sp, self.adc = (tables[g] for g in GROUPS)

        starts = [tab["timestamp"][0] for tab in (self.esc, self.sp, self.adc)
                  if len(tab.get("timestamp", ()))]
        if not starts:
            raise ValueError("log je prazan")
        t0 = min(starts)
        for tab in (self.esc, self.sp, self.adc):
            if "timestamp" in tab:
                tab["t"] = tab["timestamp"] - t0

        self.devs = (sorted(set(self.esc["esc_index"].tolist()))
                     if len(self.esc.get("esc_index", ())) else [])
        self.sp_escs = sorted(int(k[4:]) for k in self.sp if k.startswith("pwm_"))

        palette = plt.get_cmap("tab10")
        all_devs = sorted(set(self.devs) | set(self.sp_escs))
        self.color = {d: palette(i % 10) for i, d in enumerate(all_devs)}

    @staticmethod
    def name(dev):
        return f"ESC {dev}"

    def series(self, dev, col, missing=None):
        """(t, y) jednog uredjaja iz esc/, bez nepoznatih vrednosti."""
        sel = self.esc["esc_index"] == dev
        y = as_float(self.esc[col][sel], missing)
        keep = ~np.isnan(y)
        return self.esc["t"][sel][keep], y[keep]

    def has_adc(self):
        return len(self.adc.get("t", ())) > 0

    def has_warn(self):
        for d in self.devs:
            _, w = self.series(d, "error_count", -1)
            if len(w) and w.max() > 0:
                return True
        return False

    def has_rpy(self):
        vals = [as_float(self.sp[k]) for k in ("R", "P", "Y") if k in self.sp]
        return any(np.nanmax(np.abs(v), initial=0.0) > 0 for v in vals)

    def phase_changes(self):
        """[(t, faza)] na svakoj promeni faze u setpoint/."""
        if "phase" not in self.sp or not len(self.sp["phase"]):
            return []
        phases = text_column(self.sp["phase"])
        t = self.sp["t"]
        return [(t[i], p) for i, p in enumerate(phases)
                if i == 0 or p != phases[i - 1]]


# ---------------------------------------------------------------------------
# grafici - svaka funkcija crta jedan red
# ---------------------------------------------------------------------------
def plot_per_dev(ax, run, col, missing=None, t_from=0.0):
    for d in run.devs:
        t, y = run.series(d, col, missing)
        keep = t >= t_from
        if not keep.any():
            continue
        ax.plot(t[keep], y[keep], ".-", ms=3, lw=1, color=run.color[d],
                label=run.name(d))


def panel_pwm(ax, run):
    for e in run.sp_escs:
        y = as_float(run.sp[f"pwm_{e}"], -1)
        ax.step(run.sp["t"], y, where="post", lw=1.2, color=run.color[e],
                label=f"ESC {e} setpoint")
    for d in run.devs:
        t, y = run.series(d, "pwm_in", -1)
        if len(t):
            ax.plot(t, y, "o", ms=2.5, color=run.color[d],
                    label=f"ESC {d} pwm_in")
    ax.set_ylabel("PWM [us]")


def panel_rpm(ax, run):
    plot_per_dev(ax, run, "rpm")
    ax.set_ylabel("rpm")


def panel_current(ax, run):
    plot_per_dev(ax, run, "current")
    ax.set_ylabel("struja [A]")


def panel_voltage(ax, run):
    plot_per_dev(ax, run, "voltage")
    ax.set_ylabel("napon [V]")


def panel_temp(ax, run):
    plot_per_dev(ax, run, "temp_c")
    ax.set_ylabel("temp [°C]")


def panel_throttle(ax, run):
    plot_per_dev(ax, run, "power_pct")
    for d in run.devs:
        t, y = run.series(d, "pwm_out", -1)
        if len(t):
            ax.plot(t, y, "--", lw=1, color=run.color[d],
                    label=f"ESC {d} pwm_out")
    ax.set_ylabel("gas [%]")


def panel_adc(ax, run):
    cols = [k for k in run.adc if k.startswith("adc")]
    for k in cols:
        ax.plot(run.adc["t"], run.adc[k], lw=1, label=k)
    if all(not np.any(run.adc[k]) for k in cols):
        ax.text(0.5, 0.5, "sve vrednosti 0 - AD7705 ne meri?",
                transform=ax.transAxes, ha="center", va="center", alpha=0.6)
    ax.set_ylabel("ADC [V]")


def panel_adc_diff(ax, run):
    """Napon koji javlja ESC minus njegov ADC kanal, ADC interpoliran na
    trenutke ESC uzoraka. Nule iz ADC-a (AD7705 ne meri) se preskacu."""
    for d in run.devs:
        col = ADC_OF_ESC.get(d)
        if col not in run.adc:
            continue
        ok = run.adc[col] != 0
        t_adc, v_adc = run.adc["t"][ok], run.adc[col][ok]
        t, v = run.series(d, "voltage")
        keep = (t >= t_adc[0]) & (t <= t_adc[-1]) if len(t_adc) else t < 0
        if not keep.any():
            continue
        diff = v[keep] - np.interp(t[keep], t_adc, v_adc)
        ax.plot(t[keep], diff, ".-", ms=3, lw=1, color=run.color[d],
                label=f"{run.name(d)} - {col}")
    ax.axhline(0, color="black", lw=0.6)
    ax.set_ylabel("ESC - ADC [V]")


def panel_warn(ax, run):
    seen = 0
    for d in run.devs:
        t, y = run.series(d, "error_count", -1)
        if len(t):
            ax.step(t, y, where="post", lw=1.2, color=run.color[d],
                    label=run.name(d))
            seen |= int(np.bitwise_or.reduce(y.astype(int)))
    names = [n for bit, n in KDE_WARN_BITS.items() if seen & (1 << bit)]
    ax.set_ylabel("warn")
    ax.set_title("KDE warn: " + ", ".join(names), fontsize=8, loc="left")


def panel_trpy(ax, run):
    for k in ("T", "R", "P", "Y"):
        if k in run.sp:
            ax.plot(run.sp["t"], run.sp[k], lw=1, label=k)
    ax.set_ylabel("T / R / P / Y")


def mark_phases(axes, run, t_from=0.0):
    """Vertikalna linija na svakoj promeni faze, ime faze iznad prvog reda."""
    top = axes[0]
    trans = mtransforms.blended_transform_factory(top.transData, top.transAxes)
    for t, phase in run.phase_changes():
        if t < t_from:
            continue
        for ax in axes:
            ax.axvline(t, color="gray", lw=0.8, ls=":")
        top.text(t, 1.02, phase, transform=trans, rotation=90,
                 va="bottom", ha="center", fontsize=7)


def current_figure(path, run, t_from):
    """Poseban prozor samo sa strujom, od t_from [s] do kraja. None ako tada
    nema uzoraka."""
    fig, ax = plt.subplots(figsize=(14, 4.5))
    plot_per_dev(ax, run, "current", t_from=t_from)
    if not ax.lines:
        plt.close(fig)
        print(f"nema struje posle {t_from:g} s, ne crtam je posebno")
        return None

    ax.grid(True, alpha=0.3)
    ax.legend(loc="upper left", fontsize=7, ncol=2)
    mark_phases([ax], run, t_from)
    ax.set_xlim(left=t_from)
    ax.set_xlabel("vreme [s]")
    ax.set_ylabel("struja [A]")
    fig.suptitle(f"{os.path.basename(old_run_base(path) or path)}"
                 f" - struja od {t_from:g} s")
    fig.tight_layout()
    return fig


def adc_diff_figure(path, run):
    """Poseban prozor sa razlikom ESC - ADC. None ako nema ADC-a u logu."""
    if not run.has_adc():
        return None
    fig, ax = plt.subplots(figsize=(14, 4.5))
    panel_adc_diff(ax, run)
    ax.grid(True, alpha=0.3)
    if ax.get_legend_handles_labels()[0]:
        ax.legend(loc="upper left", fontsize=7, ncol=2)
    mark_phases([ax], run)
    ax.set_xlabel("vreme [s]")
    fig.suptitle(f"{os.path.basename(old_run_base(path) or path)}"
                 f" - napon ESC - ADC")
    fig.tight_layout()
    return fig


def plot_run(path, run, out, current_from):
    panels = [panel_pwm, panel_rpm, panel_current, panel_voltage,
              panel_temp, panel_throttle]
    if run.has_adc():
        panels.append(panel_adc)
    if run.has_warn():
        panels.append(panel_warn)
    if run.has_rpy():
        panels.append(panel_trpy)

    fig, axes = plt.subplots(len(panels), 1, sharex=True,
                             figsize=(14, 2.1 * len(panels) + 1.5))
    for ax, panel in zip(axes, panels):
        panel(ax, run)
        ax.grid(True, alpha=0.3)
        if ax.get_legend_handles_labels()[0]:
            ax.legend(loc="upper left", fontsize=7, ncol=2)

    mark_phases(axes, run)
    axes[-1].set_xlabel("vreme [s]")
    fig.suptitle(os.path.basename(old_run_base(path) or path))
    fig.tight_layout()
    extra = {"_struja": current_figure(path, run, current_from),
             "_esc_adc": adc_diff_figure(path, run)}

    if out:
        fig.savefig(out, dpi=150)
        print(f"sacuvano: {out}")
        root, ext = os.path.splitext(out)
        for suffix, f in extra.items():
            if f:
                f.savefig(f"{root}{suffix}{ext}", dpi=150)
                print(f"sacuvano: {root}{suffix}{ext}")
    else:
        plt.show()


def print_summary(run):
    """Kratak pregled u terminalu: trajanje i po uredjaju broj uzoraka i max rpm."""
    t_end = max(tab["t"][-1] for tab in (run.esc, run.sp, run.adc)
                if len(tab.get("t", ())))
    print(f"trajanje {t_end:.1f} s")
    for d in run.devs:
        _, rpm = run.series(d, "rpm")
        top = f"{rpm.max():.0f}" if len(rpm) else "--"
        print(f"  {run.name(d):8s} {len(rpm):5d} uzoraka, max rpm {top}")


def main():
    p = argparse.ArgumentParser(description="sve bitno iz .h5 loga ESC-ova")
    p.add_argument("log", nargs="?",
                   help="putanja ili deo imena loga (podrazumevano poslednji)")
    p.add_argument("--log-dir", default=DEF_LOG_DIR,
                   help=f"gde se trazi log (podrazumevano {DEF_LOG_DIR})")
    p.add_argument("--out", help="sacuvaj sliku (npr. log.png) umesto prozora")
    p.add_argument("--current-from", type=float, default=CURRENT_FROM,
                   help="poseban prozor sa strujom od ovog trenutka [s] "
                        f"(podrazumevano {CURRENT_FROM:g})")
    args = p.parse_args()

    path = find_log(args.log, args.log_dir)
    print(f"log: {path}")
    try:
        run = Run(load_run(path))
    except ValueError as e:
        sys.exit(f"{path}: {e}")
    print_summary(run)
    plot_run(path, run, args.out, args.current_from)


if __name__ == "__main__":
    main()
