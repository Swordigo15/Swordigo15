#include <stdio.h>

typedef struct Student{
    char name[20];
    char NIM[9];
    unsigned int age;
    union Nilai{
        unsigned int mid;
        unsigned int fin;
        unsigned int avg;
    } nilai;
}student;

int ChooseMenu();

int main()
{
    FILE *datPtr = NULL;
    student s;
    
    if((datPtr = fopen("student.dat", "rb+")) == 0){
        puts("\"student.dat\" could not be found");
    }else{
        int choice = 0; 
        
        while ((choice = ChooseMenu()) != 5) {
            switch(choice){
                case 1:
                break;
                default:
                    puts("Unrecognizable input");
                break;
            }
        }
    }
}

void Save(FILE *readPtr){
    FILE *writePtr = NULL;
    
    if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
        puts("\"accounts.txt\" could not be opened.");
    }
    else {
        rewind(readPtr);
        fprintf(writePtr, "%-6s%-21s%-10s%-6s%-6s%-6s",
                "No.", "Name", "NIM", "Mid", "Final", "Average");
                
        while(!feof){
            student sData = {"", "", 0, { 0 }};
            
        }
    }
}

int ChooseMenu(){
    printf("\t\t%s\n\t\t%s\n", 
            "----------MENU----------",
            "1. Insert Nilai");
    
    int c;
    scanf("%d", &c);
}
