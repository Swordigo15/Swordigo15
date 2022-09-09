#include <stdio.h>
#include <stdbool.h>

int Hitung(int, int, char);

int main()
{
    int floatLenght;
    
    float num1, num2;
    float answer;
    
    char opt, out;
    
    bool isLanjut = false;
    
    for(int i; i > -1; i++){
        if(isLanjut == true){
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
            default:
                printf(" = %.4f\n", answer);
                break;
        }
        
        printf("Lanjutkan Operasi? y/n ");
        scanf("%s", &out);
        
        switch(out){
            case 'y':
            case 'Y':
                isLanjut = true;
                num1 = answer;
                break;
            /*case 'New':
            case 'new':
                isLanjut = false;
                break;*/
            case 'n':
            case 'N':
                i = -2;
                break;
        }
        
        puts("=============================================================");
    }
}

int Hitung(int m, int n, char o){
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
            return m / n;
            break;
        case '%':
            return (int)m % n;
            break;
        default :
            printf("Saya tidak mengerti operasi itu.");
            return 0;
            break;
    }
    return 0;
}
