#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void CekLetakData(int*); //Prototype Function

bool end;               //variabel boolean untuk menghentikan program

int main()
{
    do{
        int* address;                                           //pointer dengan tipe integer
        int data;                                               //data yang akan disimpan ke pointer
        printf("Masukkan data (int) "); scanf("%d", &data);     //user memasukkan data yang ingin dimasukkan ke pointer

        address = &data;        //Inisialisasi pointer

        CekLetakData(address);  //memanggil function CekLetakData

        char c;
        printf("Ganti data? (y/n) "); scanf("%s", &c); //menanyakan pada user apabila ingin emngganti data yang disimpan
        switch(c){
            case 'y':   //jika input 'y' program akan mengulang
                break;
            case 'n':   //jika input 'n' program akan behenti
            default:
                end = true;
        }
    }while(end != true); //loop akan berhenti apabila variabel "end" bernilai true
}

void CekLetakData(int* d){          //Function untuk mengoutputkan lokasi data di memori
    printf("Data %d terletak di %p\n\n", *d, d);
}
