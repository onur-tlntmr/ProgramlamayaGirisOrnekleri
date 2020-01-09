#include "DirekTip1.h"

DirekTip1::DirekTip1(){
                r = 600;//Yeni değerler giriliyor
                e = 0.9;
                sty = 5.8;
                h_hoban_ustu = 1.75;
                h_hoban_fider = 1.5;
                lf = 1.25;
                
                db = direkBoyuHesapla(); //Güncel değerlere göre tekrar hesaplanıyor
                h = db - h_batma;
                hs = sty + e;
                hp = hs + sy;
                ht = e + sty + sy - 0.25;
                hf = hp+h_hoban_fider;
                hpn = hs + (sy/2);
            
            }

float::DirekTip1::toplamMomentHesapla(){
    return ((radyalMomentHesapla()+duseyMomentHesapla())*1.5)+(ruzgarMomentHesapla()*1.3);
}

float::DirekTip1::duseyMomentHesapla(){
    return (69.89*(i-f))+(60*i/2)+(65.86*lf)+(32.02*d)+(128.23*i);
}
