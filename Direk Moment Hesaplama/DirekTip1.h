#include "Direk.h"
#ifndef DIREKTIP1_H
#define DIREKTIP1_H
class DirekTip1:public Direk{

    public:
            DirekTip1();
            float toplamMomentHesapla();

        private:
            float duseyMomentHesapla();    
};
#endif