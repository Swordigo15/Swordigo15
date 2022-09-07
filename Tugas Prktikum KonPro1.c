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
        switch(key[i]){
            case 'A':
            case 'a':
                EncriptedMassage[i] = 1;
                break;
            case 'B':
            case 'b':
                EncriptedMassage[i] = 1;
                break;
            case 'C':
            case 'c':
                EncriptedMassage[i] = 1;
                break;
            case 'D':
            case 'd':
                EncriptedMassage[i] = 1;
                break;
            case 'E':
            case 'e':
                EncriptedMassage[i] = 1;
                break;
            //===============================
            case 'F':
            case 'f':
                EncriptedMassage[i] = 1;
                break;
            case 'G':
            case 'g':
                EncriptedMassage[i] = 1;
                break;
            case 'H':
            case 'h':
                EncriptedMassage[i] = 1;
                break;
            case 'I':
            case 'i':
                EncriptedMassage[i] = 1;
                break;
            case 'J':
            case 'j':
                EncriptedMassage[i] = 1;
                break;
            //===============================   
        }
    }
}
