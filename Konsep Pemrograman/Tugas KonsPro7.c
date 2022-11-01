#include <stdio.h>

typedef struct Student{
    unsigned int number;
    char firstName[10];
    char lastName[10];
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
    Statistik
};

int ChooseMenu();
void Save(FILE*);
void InputData(FILE*);
void CreateData(FILE*);
void DisplayData(FILE*);

int main()
{
    FILE *datPtr = NULL;

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
                case 3:
                    DisplayData(datPtr);
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
        fprintf(writePtr, "%-6s%-11s%-11s%-10s%-6s%-6s\n",
                "No.", "First Name", "Last Name", "NIM", "Age", "Grade");

        while(!feof(readPtr)){
            student sData = {0, "", "", "", 0, { 0 }};
            size_t result = fread(&sData, sizeof(student), 1, readPtr);

            if (result != 0 && sData.number != 0) {
                fprintf(writePtr, "%-6d%-11s%-11s%-10s%-6d%-6d\n",
                        sData.number, sData.firstName, sData.lastName, sData.NIM, sData.age,
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
    while(num <= 0 || num > 159){
        printf("\t\tEnter your last three number of NIM: "); scanf("%d", &num);
        if(num > 159) puts("max NIM is 159");
    }

    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

    student sData = {0, "", "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);

    if(sData.number == 0){
        printf("\t\tNIM L0122%.3d has no information.\n", num);
    }else{
        printf("\t\t%-6d%-11s%-11s%-10s%-6d\n", sData.number, sData.firstName, sData.lastName, sData.NIM, sData.age);
        printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s",
                "Input grade of : ",
                "1. Digital System",
                "2. Programming",
                "3. Calculus",
                "4. Physics",
                "5. Statistc",
                "Your choice ");

        int c;
        unsigned int g;
        scanf("%d", &c);
        printf("\t\tEnter your grade "); scanf("%u", &g);
        switch(c){
            case SisDig:
                sData.grade.sisDig = g;
            break;
            case KonPro:
                sData.grade.konPro = g;
            break;
            case Kalkulus:
                sData.grade.kalku = g;
            break;
            case Fisika:
                sData.grade.fisika = g;
            break;
            case Statistik:
                sData.grade.statis = g;
            break;
        }

        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void CreateData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\tEnter your last three number of NIM: "); scanf("%d", &num);
        if(num > 159) puts("max NIM is 159");
    }

    fseek(fPtr, (num - 1) *  sizeof(student), SEEK_SET);

    student sData = {0, "", "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);

    if(sData.number != 0){
        printf("\t\tNIM L0122%.3d already has information.\n", num);
    }else{
        printf("\t\tEnter your first name\t"); scanf("%s", sData.firstName);
        printf("\t\tEnter your last name\t"); scanf("%s", sData.lastName);
        printf("\t\tEnter your age\t"); scanf("%u", &sData.age);

        sData.number = num;
        sprintf(sData.NIM, "L0122%.3d", num);

        fseek(fPtr, (sData.number - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void DisplayData(FILE *readPtr){
    printf("\t\t%-6s%-11s%-11s%-10s%-6s\n",
            "No.", "First Name", "Last Name", "NIM", "Age");
    
    for(int i = 1; i <= 159; i++){
        fseek(readPtr, (i - 1) * sizeof(student), SEEK_SET);

        student sData = {0, "", "", "", 0, { 0 }};
        fread(&sData, sizeof(student), 1, readPtr);
        
        if(sData.number != 0){
            printf("\t\t%-6d%-11s%-11s%-10s%-6d\n", 
                    sData.number, sData.firstName, 
                    sData.lastName, sData.NIM, sData.age);
        }
    }
}

int ChooseMenu(){
    printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s",
            "---------------------MENU---------------------",
            "1. Insert Grade",
            "2. Create New",
            "3. Display Student",
            "5. End Program",
            "Your choice ");

    int c;
    scanf("%d", &c);
    return c;
}
