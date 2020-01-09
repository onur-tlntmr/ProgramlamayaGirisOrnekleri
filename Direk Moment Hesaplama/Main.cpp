#include<iostream>
#include "Direk.h"
#include "DefaultDirek.h"
#include "DirekTip1.h"
#include "DirekTip2.h"

using namespace std;
 

void bilgiBastir(string s,Direk  *d){
    cout<<"############ "<<s<<" ############"<<endl;
    cout<<"Direk Boyu: "<<d->direkBoyuHesapla()<<" Toplam Moment: "<<d->toplamMomentHesapla()<<endl;
    cout<<"#######################################"<<endl<<endl;
}


int main(){

    bilgiBastir("Default Direk",new DefaultDirek());

    bilgiBastir("Direk Tip 1 ",new DirekTip1());

    bilgiBastir("Direk Tip 2", new DirekTip2());

    
    return EXIT_SUCCESS;
}