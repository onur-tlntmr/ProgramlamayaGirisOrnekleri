#include"DirekTip2.h"
//Basıya calisan, fider hat tarafının aksine asılmış


DirekTip2::DirekTip2(){
                r = 760;//Yeni değerler giriliyor
                e = 0.2;
                h_batma = 1.4;
                h_hoban_ustu = 1.6;
                h_hoban_fider = 1.4;
                lf = 1.25;
                f = 0.2,f1=0.2,f2=0.2;
                i=3.3;
                
                db = direkBoyuHesapla(); //Güncel değerlere göre tekrar hesaplanıyor
                h = db - h_batma;
                hs = sty + e;
                hp = hs + sy;
                ht = e + sty + sy - 0.25;
                hf = hp+h_hoban_fider;
                hpn = hs + (sy/2);
}


float::DirekTip2::toplamMomentHesapla(){
    return ((radyalMomentHesapla()+duseyMomentHesapla())*1.5)+(ruzgarMomentHesapla()*1.3);
}

float::DirekTip2::duseyMomentHesapla(){
    return (69.89*(i+f))+(60*i/2)-(65.86*lf)+(32.02*d)+(128.23*i);
}