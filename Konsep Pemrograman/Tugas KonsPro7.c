#include <stdio.h>

typedef struct {
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
void UpdateData(FILE*);
void CreateData(FILE*);
void DisplayData(FILE*);
void DeleteData(FILE*);
void printBinary(unsigned int, int);

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
                    UpdateData(datPtr);
                    Save(datPtr);
                break;
                case 2:
                    CreateData(datPtr);
                    Save(datPtr);
                break;
                case 3:
                    DisplayData(datPtr);
                break;
                case 4:
                    DeleteData(datPtr);
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
    puts("\t\t|File saved");
}

void UpdateData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Enter your last three number of NIM: "); scanf("%d", &num);
        if(num > 159) puts("\t\t|max NIM is 159");
    }

    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

    student sData = {0, "", "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);

    if(sData.number == 0){
        printf("\t\t|NIM L0122%.3d has no information.\n", num);
    }else{
        printf("\t\t|%-6d%-11s%-11s%-10s%-6d\n", sData.number, sData.firstName, sData.lastName, sData.NIM, sData.age);
        printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s",
                "|Input grade of : ",
                "|\t1. Digital System",
                "|\t2. Programming",
                "|\t3. Calculus",
                "|\t4. Physics",
                "|\t5. Statistc",
                "|\tYour choice ");

        int c;
        unsigned int g;
        scanf("%d", &c);
        printf("\t\t|Enter your grade "); scanf("%u", &g);
        switch(c){
            case SisDig:
                sData.grade.sisDig = g;
                printf("|Your Digital System grade is "); printBinary((unsigned)g), 6);
                puts("");
            break;
            case KonPro:
                sData.grade.konPro = g;
                printf("|Your Programming grade is "); printBinary((unsigned)g), 6);
                puts("");
            break;
            case Kalkulus:
                sData.grade.kalku = g;
                printf("|Your Calculus grade is "); printBinary((unsigned)g), 6);
                puts("");
            break;
            case Fisika:
                sData.grade.fisika = g;
                printf("|Your Physics grade is "); printBinary((unsigned)g), 6);
                puts("");
            break;
            case Statistik:
                sData.grade.statis = g;
                printf("|Your Statistic grade is "); printBinary((unsigned)g), 6);
                puts("");
            break;
        }

        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void CreateData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Enter your last three number of NIM: "); scanf("%d", &num);
        if(num > 159) puts("\t\t|max NIM is 159");
    }

    fseek(fPtr, (num - 1) *  sizeof(student), SEEK_SET);

    student sData = {0, "", "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);

    if(sData.number != 0){
        printf("\t\t|NIM L0122%.3d already has information.\n", num);
    }else{
        printf("\t\t|Enter your first name\t"); scanf("%s", sData.firstName);
        printf("\t\t|Enter your last name\t"); scanf("%s", sData.lastName);
        printf("\t\t|Enter your age\t"); scanf("%u", &sData.age);

        sData.number = num;
        sprintf(sData.NIM, "L0122%.3d", num);

        fseek(fPtr, (sData.number - 1) * sizeof(student), SEEK_SET);

        fwrite(&sData, sizeof(student), 1, fPtr);
    }
}

void DeleteData(FILE *fPtr){
    int num = 0;
    while(num <= 0 || num > 159){
        printf("\t\t|Enter your last three number of NIM: "); scanf("%d", &num);
        if(num > 159) puts("max NIM is 159");
    }
    
    fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);
    
    student sData = {0, "", "", "", 0, { 0 }};
    fread(&sData, sizeof(student), 1, fPtr);
    
    if(sData.number == 0){
        printf("\t\tNIM L0122%.3d has no information.\n", num);
    }else{
        fseek(fPtr, (num - 1) * sizeof(student), SEEK_SET);
        
        student blankData = {0, "", "", "", 0, { 0 }};
        
        fwrite(&blankData, sizeof(student), 1, fPtr);
        
    }
}

void DisplayData(FILE *readPtr){
    printf("\t\t%-6s%-11s%-11s%-10s%-6s\n",
            "|No.", "First Name", "Last Name", "NIM", "Age");
    
    for(int i = 1; i <= 159; i++){
        fseek(readPtr, (i - 1) * sizeof(student), SEEK_SET);

        student sData = {0, "", "", "", 0, { 0 }};
        fread(&sData, sizeof(student), 1, readPtr);
        
        if(sData.number != 0){
            printf("\t\t|%-6d%-11s%-11s%-10s%-6d\n", 
                    sData.number, sData.firstName, 
                    sData.lastName, sData.NIM, sData.age);
        }
    }
}

void printBinary(unsigned int n, int bitLength) {
    for (unsigned int i = 1 << (bitLength - 1); i > 0; i /= 2) {
        if ((n & i) != 0) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}

int ChooseMenu(){
    printf("\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s\n\t\t%s",
            "---------------------MENU---------------------",
            "|1. Insert Grade",
            "|2. Create New",
            "|3. Display Student",
            "|4. Delete Student Data",
            "|5. End Program",
            "|Your choice ");

    int c;
    scanf("%d", &c);
    return c;
}
