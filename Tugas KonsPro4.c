#include <stdio.h>
#include <math.h>

float Luas(int, float, float);
float Keliling(int, float, float, float);

void main()
{
    float x, y, z;
    float l;
    float k;
    
    int pilihanBangun;
    puts("Jenis Bangun : ");
    puts(" 1. Persegi");
    puts(" 2. Persegi Panjang");
    puts(" 3. Segitiga");
    puts(" 4. Lingkaran");
    printf("Pilihan anda : "); scanf("%d", &pilihanBangun);
    
    puts("======================================");
    
    int jenis;
    puts("Pilih operasi : ");
    puts(" 1. Luas");
    puts(" 2. Keliling");
    printf("Pilihan anda : "); scanf("%d", &jenis);
    
    puts("");
    switch(jenis){
        case 1:
            l = Luas(pilihanBangun, x, y);
            printf("Luas     : %f\n", l);
            break;
        case 2:
            k = Keliling(pilihanBangun, x, y, z);
            printf("Keliling : %f", k);
            break;
        default:
            puts("Operasi Tidak tersedia.");
            break;
    }
}

float Luas(int j, float panjang, float lebar){
    switch(j){
        case 1 :
            printf("Panjang sisi persegi : ");
            scanf("%f", &panjang);
            return pow(panjang, 2);
            break;
        case 2 :
            printf("Panjang persegi panjang : ");
            scanf("%f", &panjang);
            printf("Lebar persegi panjang   : ");
            scanf("%f", &lebar);
            return panjang * lebar;
            break;
        case 3 :
            printf("Alas sisi Segitiga   : ");
            scanf("%f", &panjang);
            printf("Tinggi sisi Segitiga : ");
            scanf("%f", &lebar);
            return (panjang * lebar) / 2;
            break;
        case 4 :
            printf("Panjang jari-jari lingkaran : ");
            scanf("%f", &panjang);
            return 3.14 * pow(panjang, 2);
            break;
    }
    return 0;
}

float Keliling(int j, float panjang, float lebar, float sisi3){
    switch(j){
        case 1 :
            printf("Panjang sisi persegi : ");
            scanf("%f", &panjang);
            return 4 * panjang;
            break;
        case 2 :
            printf("Panjang persegi panjang : ");
            scanf("%f", &panjang);
            printf("Lebar persegi panjang : ");
            scanf("%f", &lebar);
            return (panjang + lebar) * 2;
            break;
        case 3 :
            printf("Sisi 1 sisi Segitiga : ");
            scanf("%f", &panjang);
            printf("Sisi 2 sisi Segitiga : ");
            scanf("%f", &lebar);
            printf("Sisi 3 sisi Segitiga : ");
            scanf("%f", &sisi3);
            return panjang + lebar + sisi3;
            break;
        case 4 :
            printf("Panjang diameter lingkaran : ");
            scanf("%f", &panjang);
            return 3.14 * panjang;
            break;
    }
    return 0;
}
