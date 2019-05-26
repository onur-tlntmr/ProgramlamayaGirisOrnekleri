#ifndef _library_h
#define _library_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define R 6371 // Verilen kilometre sabiti

double* processFile(FILE *f){ // dosyadaki dereceleri okuyan fonksiyon
    
    char *line; // okunan satır
    size_t len = 0; 
    size_t read = 0;
    double *array = (double*)malloc(sizeof(double)*4); // sonuç için dizi oluşturuluyor

    read = getline(&line, &len, f); // satır okundu

    line = strtok(line," "); // dereceler arasındaki boşluklar ayrıştırıldı
    int count = 0; // dongu sayısı sayılıyor
    while(line != NULL){
        array[count] = atof(line); // okunan satır double olarak diziye atılıyor
        line = strtok(NULL," ");
        count++;
    }

    if(count<3) // dosyada eksik veri varsa NULL dönüyor
        return NULL;

    return array;

}


double ortodrom(double *array){ // double dizideki degerlerden ortodom hesaplıyor

    return R*acos(sin(array[0])*sin(array[2])+cos(array[0])*cos(array[2])*cos(array[1]-array[3]));
}



#endif