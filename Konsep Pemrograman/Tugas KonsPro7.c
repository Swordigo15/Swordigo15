#include <stdio.h>

typedef struct Student{
    unsigned int number;
    char name[20];
    char NIM[9];
    unsigned int age;
    union Grade{
        unsigned int sisDig;
        unsigned int konPro;
        unsigned int kalku;
        unsigned int fisika;
        unsigned int statis;
    } grade;
}student;

enum Course { 
    SisDig = 1, KonPro,
    Kalkulus, Fisika,
    Statistiik
};

int ChooseMenu();
void Save(FILE*);
void InputData(FILE*);
void CreateData(FILE*);

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
                    InputData(datPtr);
                    Save(datPtr);
                break;
                case 2:
                    CreateData(datPtr);
                    Save(datPtr);
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
        fprintf(writePtr, "%-6s%-21s%-10s%-6s%-6s",
                "No.", "Name", "NIM", "Age", "Grade");
                
        while(!feof){
            student sData = {0, "", "", 0, { 0 }};
            size_t result = fread(&sData, sizeof(student), 1, readPtr);

            if (result != 0 && sData.number != 0) {
                fprintf(writePtr, "%-6d%-21s%-10s%-6d%-6d", 
                        sData.number, sData.name, sData.NIM, sData.age, 
                        sData.grade.sisDig + sData.grade.konPro + sData.grade.kalku
                        + sData.grade.fisika + sData.grade.statis);
            }
        }
        fclose(writePtr);
    }
    puts("\t\tFile saved");
}

void InputData(FILE *fPtr){
    int num = 0;
    printf("\t\tEnter your last three number of NIM: "); scanf("%d", &num);
    
    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);
    
    student sData = {0, "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);
    
    if(sData.number == 0){
        printf("\t\tNIM L0122%.3d has no information.\n", num);
    }else{
        printf("\t\t%-6d%-21s%-10s%-6d\n", sData.number, sData.name, sData.NIM, sData.age);
        
        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void CreateData(FILE *fPtr){
    int num = 0;
    printf("\t\tEnter your last three number of NIM: "); scanf("%d", &num);
    
    fseek(fPtr, (num - 1) *  sizeof(student), SEEK_SET);
    
    student sData = {0, "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);
    
    if(sData.number != 0){
        printf("\t\tNIM L0122%.3d already has information.\n", num);
    }else{
        printf("\t\tEnter your name\t"); scanf("%19s", sData.name);
        printf("\t\tEnter your age\t"); scanf("%5d", &sData.age);
        
        sData.number = num;
        sprintf(sData.NIM, "L0122%.3d", num);
        
        fseek(fPtr, (sData.number - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
    
}

int ChooseMenu(){
    printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s", 
            "----------MENU----------",
            "1. Insert Grade",
            "2. Create New",
            "5. End Program",
            "Your choice ");
    
    int c;
    scanf("%d", &c);
    return c;
}
