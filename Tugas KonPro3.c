#include <stdio.h>

int main()
{
    int floatLenght;
    float num1, num2;
    
    char opt, out;
    
    float answer;
    
    for(int i; i > -1; i++){
        
        puts("=======================KALKULATOR============================");
        puts("Angka pertama [spasi] operasi [spasi] angka kedua, lalu Enter");
        puts("Jenis operasi :");
        puts("  1. [+] Penjumlahan");
        puts("  2. [-] Pengurangan");
        puts("  3. [*] Perkalian");
        puts("  4. [/] Pembagian");
        puts("  5. [\%] sisa");
        puts("");
        printf("Panjang angka dibelakang koma : ");
        scanf("%d", &floatLenght);
        puts("");
        scanf("%f %s %f", &num1, &opt, &num2);
        
        switch(opt){
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
            case '%':
                answer = (int)num1 % (int)num2;
                break;
            default :
                printf("Saya tidak mengerti operasi itu.");
                break;
        }
        
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
        
        printf("Lanjutkan? y/n ");
        scanf("%s", &out);
        
        switch(out){
            case 'y':
            case 'Y':
                break;
            case 'n':
            case 'N':
                i = -2;
                break;
        }
        
        puts("=============================================================");
    }
}
