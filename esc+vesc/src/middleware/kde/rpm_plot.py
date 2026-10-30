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

Cita nov format (jedan <tag>_<vreme>.h5 sa grupama esc/, setpoint/, adc/) i
stari (tri fajla _esc.h5, _setpoint.h5, _adc.h5 - zadaje se bilo koji od njih
ili deo imena). Moze i dok esc_control.py jos pise isti log.

Grafici, odozgo nadole:
    PWM [us]        poslat setpoint po ESC-u (linija) i pwm_in - sta ESC sam
                    cita na ulazu gasa (tacke, ista boja)
    rpm             KDE ESC-ovi i VESC
    struja [A]
    napon [V]       sta javljaju ESC-ovi / VESC
    temperatura     KDE: ESC, VESC: FET
    gas / duty [%]  KDE: gas iz setpointa, VESC: izmereni duty; KDE pwm_out
                    (objekat 7, sirovo) isprekidano
    ADC [V]         4 napona sa AD7705 (samo ako ih ima u logu)
    warn            KDE warn bajt (samo ako je negde != 0)
    T/R/P/Y         komanda iz esc_test.py (samo ako R/P/Y nisu sve nule)
Promene faze (settle, manual, ROLL +10deg, ...) su vertikalne linije.
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

from esc_control import DEF_LOG_DIR, DEF_VESC_ID, KDE_WARN_BITS

GROUPS = ("esc", "setpoint", "adc")
RUN_SUFFIXES = ("_esc.h5", "_setpoint.h5", "_adc.h5")   # stari format, redom kao GROUPS

# rpm VESC-a se na grafiku mnozi ovim faktorom (log ostaje kakav jeste)
VESC_RPM_SCALE = 1


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
        self.kde = [d for d in self.devs if d != DEF_VESC_ID]
        self.sp_escs = sorted(int(k[4:]) for k in self.sp if k.startswith("pwm_"))

        palette = plt.get_cmap("tab10")
        all_devs = sorted(set(self.devs) | set(self.sp_escs))
        self.color = {d: palette(i % 10) for i, d in enumerate(all_devs)}

    @staticmethod
    def name(dev):
        return f"VESC {dev}" if dev == DEF_VESC_ID else f"ESC {dev}"

    def series(self, dev, col, missing=None):
        """(t, y) jednog uredjaja iz esc/, bez nepoznatih vrednosti."""
        sel = self.esc["esc_index"] == dev
        y = as_float(self.esc[col][sel], missing)
        keep = ~np.isnan(y)
        return self.esc["t"][sel][keep], y[keep]

    def has_adc(self):
        return len(self.adc.get("t", ())) > 0

    def has_warn(self):
        for d in self.kde:
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
def plot_per_dev(ax, run, col, missing=None, scale_vesc=1.0):
    for d in run.devs:
        t, y = run.series(d, col, missing)
        if not len(t):
            continue
        label = run.name(d)
        if d == DEF_VESC_ID and scale_vesc != 1.0:
            y, label = y * scale_vesc, f"{label} (x{scale_vesc:g})"
        ax.plot(t, y, ".-", ms=3, lw=1, color=run.color[d], label=label)


def panel_pwm(ax, run):
    for e in run.sp_escs:
        y = as_float(run.sp[f"pwm_{e}"], -1)
        ax.step(run.sp["t"], y, where="post", lw=1.2, color=run.color[e],
                label=f"ESC {e} setpoint")
    for d in run.kde:
        t, y = run.series(d, "pwm_in", -1)
        if len(t):
            ax.plot(t, y, "o", ms=2.5, color=run.color[d],
                    label=f"ESC {d} pwm_in")
    ax.set_ylabel("PWM [us]")


def panel_rpm(ax, run):
    plot_per_dev(ax, run, "rpm", scale_vesc=VESC_RPM_SCALE)
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
    for d in run.kde:
        t, y = run.series(d, "pwm_out", -1)
        if len(t):
            ax.plot(t, y, "--", lw=1, color=run.color[d],
                    label=f"ESC {d} pwm_out")
    ax.set_ylabel("gas / duty [%]")


def panel_adc(ax, run):
    cols = [k for k in run.adc if k.startswith("adc")]
    for k in cols:
        ax.plot(run.adc["t"], run.adc[k], lw=1, label=k)
    if all(not np.any(run.adc[k]) for k in cols):
        ax.text(0.5, 0.5, "sve vrednosti 0 - AD7705 ne meri?",
                transform=ax.transAxes, ha="center", va="center", alpha=0.6)
    ax.set_ylabel("ADC [V]")


def panel_warn(ax, run):
    seen = 0
    for d in run.kde:
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


def mark_phases(axes, run):
    """Vertikalna linija na svakoj promeni faze, ime faze iznad prvog reda."""
    top = axes[0]
    trans = mtransforms.blended_transform_factory(top.transData, top.transAxes)
    for t, phase in run.phase_changes():
        for ax in axes:
            ax.axvline(t, color="gray", lw=0.8, ls=":")
        top.text(t, 1.02, phase, transform=trans, rotation=90,
                 va="bottom", ha="center", fontsize=7)


def plot_run(path, run, out):
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

    if out:
        fig.savefig(out, dpi=150)
        print(f"sacuvano: {out}")
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
    args = p.parse_args()

    path = find_log(args.log, args.log_dir)
    print(f"log: {path}")
    try:
        run = Run(load_run(path))
    except ValueError as e:
        sys.exit(f"{path}: {e}")
    print_summary(run)
    plot_run(path, run, args.out)


if __name__ == "__main__":
    main()
