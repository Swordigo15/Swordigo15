#include <stdio.h>

int main()
{
    int charLenght;
    printf("Character amount in the text is "); scanf("%d\n", &charLenght);
    
    char text[charLenght];
    scanf("%s", text);
    
    int key[4];
    
    for(int i = 0; i < 4; i++){
        printf("Key%d : ", i + 1); scanf("%d", &key[0]);
        
        if(key[0] < 0 || key[0] > 9)
            puts("Key must be between 1 and 9");
    }
    
    int EncriptedMassage[charLenght];
    for(int i = 0; i < charLenght; i++){
        switch(text[i]){
            case 'A':
            case 'a':
                EncriptedMassage[i] = 1;
                break;
            case 'B':
            case 'b':
                EncriptedMassage[i] = 2;
                break;
            case 'C':
            case 'c':
                EncriptedMassage[i] = 3;
                break;
            case 'D':
            case 'd':
                EncriptedMassage[i] = 4;
                break;
            case 'E':
            case 'e':
                EncriptedMassage[i] = 5;
                break;
            //===============================
            case 'F':
            case 'f':
                EncriptedMassage[i] = 6;
                break;
            case 'G':
            case 'g':
                EncriptedMassage[i] = 7;
                break;
            case 'H':
            case 'h':
                EncriptedMassage[i] = 8;
                break;
            case 'I':
            case 'i':
                EncriptedMassage[i] = 9;
                break;
            case 'J':
            case 'j':
                EncriptedMassage[i] = 10;
                break;
            //===============================
            case 'K':
            case 'k':
                EncriptedMassage[i] = 11;
                break;
            case 'L':
            case 'l':
                EncriptedMassage[i] = 12;
                break;
            case 'M':
            case 'm':
                EncriptedMassage[i] = 13;
                break;
            case 'N':
            case 'n':
                EncriptedMassage[i] = 14;
                break;
            case 'O':
            case 'o':
                EncriptedMassage[i] = 15;
                break;
            //===============================
            case 'P':
            case 'p':
                EncriptedMassage[i] = 16;
                break;
            case 'Q':
            case 'q':
                EncriptedMassage[i] = 17;
                break;
            case 'R':
            case 'r':
                EncriptedMassage[i] = 18;
                break;
            case 'S':
            case 's':
                EncriptedMassage[i] = 19;
                break;
            case 'T':
            case 't':
                EncriptedMassage[i] = 20;
                break;
            //===============================
            case 'U':
            case 'u':
                EncriptedMassage[i] = 21;
                break;
            case 'V':
            case 'v':
                EncriptedMassage[i] = 22;
                break;
            case 'W':
            case 'w':
                EncriptedMassage[i] = 23;
                break;
            case 'X':
            case 'x':
                EncriptedMassage[i] = 24;
                break;
            case 'Y':
            case 'y':
                EncriptedMassage[i] = 25;
                break;
            //===============================
            case 'Z':
            case 'z':
                EncriptedMassage[i] = 26;
                break;
            case ' ':
            default:
                EncriptedMassage[i] = 0;
                break;
        }
        
        
        EncriptedMassage[i] += key[0] + key[1];
        EncriptedMassage[i] *= key[3] + key[4];
        printf("%d", EncriptedMassage[i]);
    }
}
