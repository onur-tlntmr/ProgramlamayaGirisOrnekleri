#include "Direk.h"
#ifndef DIREK_TIP_2_H
#define DIREK_TIP_2_H
class DirekTip2:public Direk{
    public:
            DirekTip2();
            float toplamMomentHesapla();

        private:
            float duseyMomentHesapla();
};
#endif