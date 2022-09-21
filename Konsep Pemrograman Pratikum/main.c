#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

time_t t;                                               //Variabel untuk menyimpan waktu dari library time.h

int Random(int, int);                                   //
unsigned long long int Faktorial(unsigned int);         //Deklarasi Prototype Function
unsigned long long int Fibonacci(unsigned int);         //

int main()
{
    srand((unsigned) time(&t));                         //Menggunakan variabel t untuk seed rand()

    char lg;                                            //Variabel untuk menyimpan pilihan
    printf("Login / Guest (l/g) "); scanf("%s", &lg);   //Meminta input dari pengguna untuk memilih menggunakan username atau guest username

    char username[10];                                  //Variabel untuk menyimpan username yang diberikan pengguna (Maksimal 10 karakter)

    switch(lg){
        case 'l':                                       //Jika pengguna menginput 'l' atau 'L'
        case 'L':
            puts("Max 10 character");
            printf("Username : "); scanf("%s", username);   //Meminta pengguna menginput username yang ingin digunakan
            printf("\nHello %s", username);                 //Output username pengguna
            break;
        case 'g':
        case 'G':
            printf("Hello User%d", Random(1000, 9999));     //Output guest user dengan menambahkan angka random antara 1000 dan 9999
            break;
        default:
            printf("default");                              //Bila input user tidak diketahui
            break;
    }

    do{
        puts("\n============Kalkulator + ============");
        puts("Pilih jenis operasi :");
        puts("  1. Faktorial");
        puts("  2. Fibonacci");

        int i;                                          //Variabel untuk menyimpan angka

        char opt;                                       //Variabel untuk menyimpan pilihan pengguna
        printf("Pilihan Anda : "); scanf("%s", &opt);   //Meminta input dari user untuk memilih operasi
        switch(opt){
            case '1':                                                               //Apabila iput adalah 'l'
                printf("\nMasukkan angka yang akan difaktorial "); scanf("%u", &i); //Meminta input angka yang akn di faktrialkan
                printf("%d! = %llu", i, Faktorial(i));                              //Output hasil faktorial
                break;
            case '2':
                printf("\nFibonacci ke-"); scanf("%u", &i);                         //Meminta input urutan bilangan fibonacci ke berapa
                printf("Fibonacci ke-%d adalah %llu", i, Fibonacci(i));             //Output bilangan fibonacci
                break;
            default:
                printf("default");                                                  //Bila input user tidak diketahui
                break;
        }
    }while(getchar() != EOF);
}

unsigned long long int Faktorial(unsigned int n){           //Fungsi untuk menghitung Faktorial
    if(n <= 1){
        return 1;
    }
    else{
        return n * Faktorial(n - 1);
    }
}

unsigned long long int Fibonacci(unsigned int n){           //Fungsi untuk menentukan Fibonacci
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int Random(int min, int max){                               //Fungsi untuk membatasi bilangan random
    return min + (rand() % max);
}
