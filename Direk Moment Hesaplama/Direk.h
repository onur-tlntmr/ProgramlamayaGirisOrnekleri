#ifndef DIREK_H
#define DIREK_H

class Direk{
    protected:
        float r,h_batma,e,i,sty,sy,f,f1,f2,h_hoban_ustu,h_hoban_fider,lf,hs,hp,ht,hf,hpn,a,a1,a2,h,d,hz,dz,db;
        Direk();
        float radyalMomentHesapla();
        float ruzgarMomentHesapla();
        virtual float duseyMomentHesapla()=0;

    public:
        float direkBoyuHesapla();
        virtual float toplamMomentHesapla()=0;
};
#endif