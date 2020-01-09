#include"DefaultDirek.h"

float::DefaultDirek::toplamMomentHesapla(){
    return ((radyalMomentHesapla()+duseyMomentHesapla())*1.5)+(ruzgarMomentHesapla()*1.3);
}

float::DefaultDirek::duseyMomentHesapla(){
    float result =   (69.89*(i-f))+(60*i/2)+(65.86*lf)+(32.02*d)+(128.23*i);
    return result;
}