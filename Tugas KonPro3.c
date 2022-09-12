#include <stdio.h>
#include <stdbool.h>

float Hitung(float, float, char);

int main()
{
    int floatLenght;
    
    float num1, num2;
    float answer;
    
    char opt, out;
    
    bool isLanjut = false;
    bool berhenti = false;
    
    while(!berhenti){
        if(isLanjut == true){
            puts("\"Hasil sebelumnya\" [spasi] operasi [spasi] angka kedua, lalu Enter");
            printf("%f ", num1);
            scanf("%s %f", &opt, &num2);
        }
        else if(isLanjut == false){
            puts("=======================KALKULATOR============================");
            puts("Angka pertama [spasi] operasi [spasi] angka kedua, lalu Enter");
            puts("Jenis operasi :");
            puts("  1. [+] Penjumlahan");
            puts("  2. [-] Pengurangan");
            puts("  3. [x] Perkalian");
            puts("  4. [/] Pembagian");
            puts("  5. [\%] sisa");
            puts("");
            printf("Panjang angka dibelakang koma : ");
            scanf("%d", &floatLenght);
            puts("");
            scanf("%f %s %f", &num1, &opt, &num2);
        }
        
        answer = Hitung(num1, num2, opt);
        
        switch(floatLenght){
            case 0:
                printf(" = %.0f\n", answer);
                break;
            case 1:
                printf(" = %.1f\n", answer);
                break;
            case 2:
                printf(" = %.2f\n", answer);
                break;
            case 3:
                printf(" = %.3f\n", answer);
                break;
            case 4:
                printf(" = %.4f\n", answer);
                break;
            case 5:
                printf(" = %.5f\n", answer);
                break;
            default:
                printf(" = %f\n", answer);
                break;
        }
        
        puts("\'y\' untuk melanjutkan operasi.");        
        puts("\'o\' untuk memulai operasi baru.");
        puts("\'n\' untuk berhenti.");
        printf("Lanjutkan Operasi? y/n/o ");
        scanf("%s", &out);
        
        switch(out){
            case 'y':
            case 'Y':
                isLanjut = true;
                num1 = answer;
                break;
            case 'O':
            case 'o':
                isLanjut = false;
                break;
            case 'n':
            case 'N':
                berhenti = true;
                break;
        }
        
        puts("=============================================================");
    }
}

float Hitung(float m, float n, char o){
    switch(o){
        case '+':
            return m + n;
            break;
        case '-':
            return m - n;
            break;
        case '*':
        case 'x':
            return m * n;
            break;
        case '/':
            if(n != 0){
                return m / n;
            }
            else{
                puts("Tidak bisa membagi dengan 0");
            }
            break;
        case '%':
            return (int)m % (int)n;
            break;
        default :
            printf("Saya tidak mengerti operasi itu.");
            return 0;
            break;
    }
    return 0;
}
