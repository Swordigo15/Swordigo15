#include <stdio.h>

int main()
{
    int choice;
    puts("1. Encripter");
    puts("2. Interpreter");
    puts("Your choice : "); scanf("%d", &choice);
    
    if(choice == 1){
        int charLenght;
        puts("========WELCOME TO WORD ENCRIPTOR v.1.0.0========");
        puts("--------- by Muhammad Annys (L0122102) ----------");
        printf("Character amount in the text is "); scanf("%d", &charLenght);
        
        char text[charLenght];
        scanf("%s", text);
        
        unsigned int key[4];
        unsigned int passKey;
        
        puts("Key must be between 1 and 9");
        
        for(int i = 0; i < 4; i++){
            printf("Key%d : ", i + 1); scanf("%d", &key[i]);
            
            passKey += key[i];
            
            if(key[i] < 0 || key[i] > 9){
                puts("Key must be between 1 and 9");
                passKey -= key[i];
                i--;
            }
        }
        
        printf("\nYour Encripted massage is ");
        int EncriptedMassage[charLenght];
        for(int i = 0; i < charLenght; i++){
            switch(text[i]){
                case 'A':
                case 'a':
                    EncriptedMassage[i] = 10;
                    break;
                case 'B':
                case 'b':
                    EncriptedMassage[i] = 11;
                    break;
                case 'C':
                case 'c':
                    EncriptedMassage[i] = 12;
                    break;
                case 'D':
                case 'd':
                    EncriptedMassage[i] = 13;
                    break;
                case 'E':
                case 'e':
                    EncriptedMassage[i] = 14;
                    break;
                //===============================
                case 'F':
                case 'f':
                    EncriptedMassage[i] = 15;
                    break;
                case 'G':
                case 'g':
                    EncriptedMassage[i] = 16;
                    break;
                case 'H':
                case 'h':
                    EncriptedMassage[i] = 17;
                    break;
                case 'I':
                case 'i':
                    EncriptedMassage[i] = 18;
                    break;
                case 'J':
                case 'j':
                    EncriptedMassage[i] = 19;
                    break;
                //===============================
                case 'K':
                case 'k':
                    EncriptedMassage[i] = 20;
                    break;
                case 'L':
                case 'l':
                    EncriptedMassage[i] = 21;
                    break;
                case 'M':
                case 'm':
                    EncriptedMassage[i] = 22;
                    break;
                case 'N':
                case 'n':
                    EncriptedMassage[i] = 23;
                    break;
                case 'O':
                case 'o':
                    EncriptedMassage[i] = 24;
                    break;
                //===============================
                case 'P':
                case 'p':
                    EncriptedMassage[i] = 25;
                    break;
                case 'Q':
                case 'q':
                    EncriptedMassage[i] = 26;
                    break;
                case 'R':
                case 'r':
                    EncriptedMassage[i] = 27;
                    break;
                case 'S':
                case 's':
                    EncriptedMassage[i] = 28;
                    break;
                case 'T':
                case 't':
                    EncriptedMassage[i] = 29;
                    break;
                //===============================
                case 'U':
                case 'u':
                    EncriptedMassage[i] = 30;
                    break;
                case 'V':
                case 'v':
                    EncriptedMassage[i] = 31;
                    break;
                case 'W':
                case 'w':
                    EncriptedMassage[i] = 32;
                    break;
                case 'X':
                case 'x':
                    EncriptedMassage[i] = 33;
                    break;
                case 'Y':
                case 'y':
                    EncriptedMassage[i] = 34;
                    break;
                //===============================
                case 'Z':
                case 'z':
                    EncriptedMassage[i] = 35;
                    break;
                case ',':
                    EncriptedMassage[i] = 36;
                    break;
                case '.':
                    EncriptedMassage[i] = 37;
                    break;
                case ' ':
                case '_':
                default:
                    EncriptedMassage[i] = 63;
                    break;
            }
            
            EncriptedMassage[i] += passKey;
                
            printf("%d ", EncriptedMassage[i]);
        }
        
        printf("\nYour password is ");
        
        for(int j = 0; j < 4; j++)
            printf("%d", key[j]);
    }
    else if(choice == 2){
        int codeLenght;
        puts("========WELCOME TO WORD INTERPRETER v.1.0.0========");
        puts("---------- by Muhammad Annys (L0122102) -----------");
        printf("The amount of number in code "); scanf("%d", &codeLenght);
        
        int code[codeLenght];
        
        unsigned int key[4];
        unsigned int passKey;
        
        puts("\nPuts space every two numbers.");
        puts("Write the code here.");
        for(int i = 0; i < codeLenght; i++){
            scanf("%d", &code[i]);
        }
        
        puts("\nPuts space every number.");
        puts("write the password(4 Numbers)");
        scanf("%d", key);
        
        for(int i = 0; i < codeLenght; i++){
            
        }
    }
    else{
        puts("I don't know");
    }
}
