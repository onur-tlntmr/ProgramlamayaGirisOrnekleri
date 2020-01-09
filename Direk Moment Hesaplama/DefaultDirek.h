#include "Direk.h"

#ifndef DEFAULT_DIREK_H
#define DEFAULT_DIREK_H

class DefaultDirek:public Direk{
    
    public:
        float toplamMomentHesapla();
        

    private:
        float duseyMomentHesapla();    
};

#endif