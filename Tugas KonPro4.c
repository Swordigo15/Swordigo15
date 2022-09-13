#include <stdio.h>
#include <math.h>

int Luas(int, int, int);

int main()
{
    int i, j;
    int luas;
    int keliling;
    
    int pilihanBangun;
    scanf("%d", &pilihan);
    
    int jenis;
    scanf("%d", &jenis);
    
    switch(jenis){
        case 1:
        break;
        case 2:
        break;
    }
    switch(pilihanBangun){
        case 1 :
            printf("Panjang sisi persegi : ");
            scanf("%d", &i);
            luas = Luas(pilihan, i, 0);
            break;
        case 2 :
            printf("Panjang persegi panjang : ");
            scanf("%d", &i);
            printf("Lebar persegi panjang : ");
            scanf("%d", &j);
            luas = Luas(pilihan, i, j);
            break;
        case 3 :
            printf("Alas sisi Segitiga : ");
            scanf("%d", &i);
            printf("Tinggi sisi Segitiga : ");
            scanf("%d", &j);
            luas = Luas(pilihan, i, j);
            break;
    }
    
    printf("luas     : %d\n", luas);
    printf("keliling : %d", keliling);
}

int Luas(int j, int panjang, int lebar){
    switch(j){
        case 1:
            return pow(panjang, 2);
            break;
        case 2:
            return panjang * lebar;
            break;
        case 3:
            return (panjang * lebar) / 2;
            break;
    }
    return 0;
}

int keliling(int j, int panjang, int lebar, int sisi3){
    switch(j){
        case 1:
            return 4 * panjang;
            break;
        case 2:
            return 2 * (panjang + lebar);
            break;
        case 3:
            return panjang + lebar + sisi3;
            break;
    }
    return 0;
}