package com.company;

import java.util.Scanner;

public class Main {

    private static String conventer(int numb){ //Çerviriyi yapan method
        int numbers[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; // sayi sisteminde ki sayilar
        String sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; // sayilara karsilik gelen harfler

        String result = ""; // Geri dondurulecek olan string
        int index =  0 ; // aradigimiz sayinin index'i

        while(numb>0) {//sayimiz bitene kadar donguyu ceviriyoruz
            while (numbers[index + 1] < numb && index < 11)  //sayinin bir bugunu bulana kadar ve eleman sayisini asmayana kadar
                index++;//index'i bir artırılıyor

            numb-=numbers[index];//Bulunan en yakin ve kucuk olan sayi cikariliyor
            result += sym[index];//cikarilan sayi neyse sonuc stringine ekleniyor
            index = 0; //Bir sonraki arama icin index sifirlaniyor
        }
        return result; //  sonuc donduruluyor
    }

    public static void main(String[] args) {

        System.out.print("Bir Sayi Giriniz: ");
        Scanner input = new Scanner(System.in);

        int numb = input.nextInt();
        System.out.println(conventer(numb));
    }
}