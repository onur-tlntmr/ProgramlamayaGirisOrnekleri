#include<stdio.h>
#include "library.h"

/*
    Dosyadan değer alıp hesaplamayı yaptım 
    artık sen sonuçları diğer dosyaya atarsın

    #derleyici bilgileri
    gcc (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0
    
    #derleme komutu
    gcc main.c -o program -lm





*/

int main(){
    
    FILE *fp; //dosya pointerı

    fp = fopen("text","r"); // dosya okuma kipinde açılıyor
    //////////////////////////////////////////Birinci satır
    double* result = processFile(fp); // dosyadan parametreler alınıyor


    double numb = ortodrom(result); // ortodom hesaplanıyor


    printf("%f\n",numb); // s

    //////////////////////////////////////////İkinci satır

    result = processFile(fp); // dosyadan parametreler alınıyor


    numb = ortodrom(result); // ortodom hesaplanıyor


    printf("%f\n",numb); // s

    fclose(fp);          // işlemi biten dosya kapatılıyor

    return EXIT_SUCCESS;

}