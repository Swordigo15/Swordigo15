#include <stdio.h>
#include <stdlib.h>

int R(int, int);

int main()
{
    do{
        int choice;
        puts("1. Encripter");
        puts("2. Interpreter");
        puts("Your choice : "); scanf("%d", &choice);
        
        if(choice == 1){
            int charLenght;
            puts("========WELCOME TO MASSAGE ENCRIPTOR v.1.0.0========");
            puts("----------- by Muhammad Annys (L0122102) -----------");
            puts("Use \'_\' for space.");
            printf("Character amount in the text is "); scanf("%d", &charLenght);
            
            char text[charLenght];
            scanf("%s", text);
            
            unsigned int key[4];
            unsigned int passKey;
            
            for(int i = 0; i < 4; i++){
                key[i] = R(0, 9);
                
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
            printf("%d ", key[j]);
            
            puts("\nPlease write it!");
            
        }
        else if(choice == 2){
            int codeLenght;
            puts("======WELCOME TO MASSAGE INTERPRETER v.1.0.0=======");
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
            for(int i = 0; i < 4; i++){
                scanf("%d", &key[i]);
                
                passKey += key[i];
            }
            
            char massage;
            for(int i = 0; i < codeLenght; i++){
                code[i] -= passKey;
                switch(code[i]){
                    case 10:
                        massage = 'a';
                        break;
                    case 11:
                        massage = 'b';
                        break;
                    case 12:
                        massage = 'c';
                        break;
                    case 13:
                        massage = 'd';
                        break;
                    case 14:
                        massage = 'e';
                        break;
                    //================
                    case 15:
                        massage = 'f';
                        break;
                    case 16:
                        massage = 'g';
                        break;
                    case 17:
                        massage = 'h';
                        break;
                    case 18:
                        massage = 'i';
                        break;
                    case 19:
                        massage = 'j';
                        break;
                    //================
                    case 20:
                        massage = 'k';
                        break;
                    case 21:
                        massage = 'l';
                        break;
                    case 22:
                        massage = 'm';
                        break;
                    case 23:
                        massage = 'n';
                        break;
                    case 24:
                        massage = 'o';
                        break;
                    //================
                    case 25:
                        massage = 'p';
                        break;
                    case 26:
                        massage = 'q';
                        break;
                    case 27:
                        massage = 'r';
                        break;
                    case 28:
                        massage = 's';
                        break;
                    case 29:
                        massage = 't';
                        break;
                    //================
                    case 30:
                        massage = 'u';
                        break;
                    case 31:
                        massage = 'v';
                        break;
                    case 32:
                        massage = 'w';
                        break;
                    case 33:
                        massage = 'x';
                        break;
                    case 34:
                        massage = 'y';
                        break;
                    //================
                    case 35:
                        massage = 'z';
                        break;
                    case 36:
                        massage = ',';
                        break;
                    case 37:
                        massage = '.';
                        break;
                    case 63:
                    default:
                        massage = ' ';
                        break;
                    //================
                }
                
                printf("%s", &massage);
            }
        }
        else{
            puts("I don't know");
        }
    }while(getchar() != EOF);
}

int R(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
