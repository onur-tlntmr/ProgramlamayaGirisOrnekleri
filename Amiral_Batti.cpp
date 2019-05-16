// AmiralBattı.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

#define SEA_COLUMN 10
#define SEA_ROW 10


int sea[SEA_COLUMN] [SEA_ROW];


int random(int rand_max) { // Rastgele 0 ile belirtilen aralıkta sayı üretir

	int a = rand() % rand_max;

	return a;
}


void addShips(int count) { //Rastgele gemi ekleyer
	
	for (int i = 0; i < count; i++) {

		int x,y;
		while(true){

			x = random(SEA_ROW);
			y = random(SEA_COLUMN);

            if(sea[x][y] == 1 )
                continue;

            sea[x][y] = 1;
            break;
		}


	}

}


void printSea() { //Hamleleler için denizi bastırır
    for (int i = 0; i < SEA_ROW; i++) {
            for (int j = 0; j < SEA_COLUMN; j++){
                

                if(sea[i][j] == 3){
                    cout<<" _0_ ";
                }
                else{
                    cout<<" ___ ";
                }

            }
                
            cout << "\n\n";
    }

	
}



void printVisiableSea(){ //Score tablosu ve debug için görünür denizi bastırır
   for (int i = 0; i < SEA_ROW; i++) {
            for (int j = 0; j < SEA_COLUMN; j++){
                
                switch (sea[i][j])
                {
                    case 0: //Gemi ve atış yoksa
                    cout<<" ___ ";
                    break;
                    case 1:
                    cout<<" _G_ "; // Gemi varsa atış yoksa 
                    break;
                    case 2:
                    cout<<" _0_ "; // Gemi yok atış varsa
                    break;
                    case 3:
                    cout<<" _X_ "; // Gemi ve atış varsa
                    break;

            }
                
    }
            cout << "\n\n";

}
}





bool isValid(string s) { // Girilen değerin geçerli olup olmadığını kontrol eder

    if(!s.empty()){ // girilen değer boş değilse
        int numb ;

        try{
            numb = stoi(s); // girilen değeri int'e çevir
        }
        catch(invalid_argument){ // çevirilemiyorsa false dönder
            return false;
        }

        if(numb > -1 && numb <10) // int ise aralığı kontrol et
            return true;
    }

	return false;
}


int* getCoordinate(){ // Kullanıcı'dan koordinatları alan method boyutu 2 olan dizi döndürür

    int* array = new int[2] ; 
    string value;
    
    while(true){
        cout<<"X Koordinatını Giriniz: ";
        
        cin>>value;
        
        if(isValid(value)){
            array[0] = stoi(value);
        }

        else{
            cout<<"Geçersiz Değer...."<<endl;
            continue;
        }
        
        cout<<"Y Koordinatını Giriniz: ";
        cin>>value;


        if(isValid(value)){
            array[1] = stoi(value);
            break;
        }

        else{
            cout<<"Geçersiz Değer...."<<endl;
            continue;
        }

    }

    return array;

}


bool fire(int* array){ // atış yapan method

    for(int i=0;i<SEA_ROW;i++) 
        for(int j=0;j<SEA_COLUMN;j++){
            int x = array[0];              //lineer search ile koordinatları bul
            int y = array[1];
            if(i == x && j == y){
                
                int* value = &sea[i][j]; //koordinatlardaki değeri al 
                //dizideki değerler değişeceği için adres alınmıştır
                if(*value == 1){ //gemi varsa
                    *value = 3; //gemi vuruldu'yu ata
                    return true;
                }

                else if(*value == 0){//gemi yoksa
                    *value = 2 ;//karavanayı at
                    
                }

                else //0 ve 1 değilse yani atış daha evvel yapılmışsa mesaj yaz
                    cout<<"Aynı koordinatlara ikinci atış yapıldı sıranızı kaybettiniz"<<endl;
                

                break;
            }
                
        }
    return false;
}


void printScore(int accurate_shot){ //sonucu ekrana yazdıran method
    
    cout<<"\n\n\nİsabetli Atış Sayısı: "<<accurate_shot<<"\n\n\n";
    
    cout<<"İsabetli Atış: _X_\tKaravana Atış: _0_\t\n\n"<<endl;


    printVisiableSea();



}



int main()
{
	srand((unsigned)time(NULL)); // zamana bağlı olarak rastege sayı üretmesini sağlar

	addShips(10);  // 10 gemi ekler 
    int accurate_shot = 0; // atış sayısını ekler

    for(int i = 0; i<10;i++){ //10 atış hakkı veridi 
        printSea(); //Denizi ekrana dök
        if(fire(getCoordinate())) // koordinatları al - atış yap 
            accurate_shot++; // doğru ise değişkieni bir artır
    }

    printScore(accurate_shot); // neticeyi ekrana bas



	return EXIT_SUCCESS; 
    
}