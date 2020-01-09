#include "Direk.h"

Direk::Direk()
{
    r = 850;
    h_batma = 1.6;
    e = 0.65;
    i = 3.25;
    sty = 5.75;
    sy = 1.4;
    f = 0.24, f1 = 0.24, f2 = 0.24;
    h_hoban_ustu = 2.6;
    h_hoban_fider = 2.15;
    lf = 1.4;
    a = 45;
    a1 = 45;
    a2 = 45;
    db = direkBoyuHesapla();
    h = db - h_batma;

    d = 0.32;
    dz = 0.28;
    hz = 0.70;


    hs = sty + e;
    hp = hs + sy;
    ht = e + sty + sy - 0.25;
    hf = hp + h_hoban_fider;
    hpn = hs + (sy / 2);
}

float ::Direk::direkBoyuHesapla()
{
    return h_batma + e + sty + sy + h_hoban_ustu;
}

float ::Direk::radyalMomentHesapla()
{
    const int TF = 1500, TT = 1100, TP = 1200, TS = 1200;

    float
        t_rf = a * TF / r,
        t_rt = a * TT / r,
        t_rp = a * TP / r,
        t_rs = a * TS / r;

    float result = (hf * t_rf) + (ht * t_rt) + (hp * t_rp) + (hs * t_rs);
    return result;
}

float ::Direk::ruzgarMomentHesapla()
{
    float
        wd = 23.1 * d * h,
        wfk = 23.1 * dz * hz;
    float result = (43.164 * hf) + (34.65 * ht) + (24.948 * hp) + (29.07 * hs) + (3.556 * hpn) + (wd * h / 2) + (wfk * (hf + hz / 2));
    return result;
}