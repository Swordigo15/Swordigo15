#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MHSCOUNT 10

typedef struct{
    char NIM    [10];
    char name   [20];
    char jk     [10];
    float IPK;
}mahasiswa;

void AddData    (FILE*);
void UpdateData (FILE*);
void DeleteData (FILE*);
void PrintData  ();
void Import     (FILE*);
void Export     (char[]);

int menu        (char[], char[]);

mahasiswa siswa[MHSCOUNT];

int main()
{
    FILE* dataFile = NULL;
    
    char fileName[15];
    char saveDataName[50];
    
    printf("Enter file Name : "); scanf("%s", fileName);
    
    sprintf(saveDataName, "%sSD.txt", fileName);
    strcat(fileName, ".txt");
    
    if((dataFile = fopen(saveDataName, "rb+")) == NULL){
        dataFile = fopen(saveDataName, "wb+");
    }
    
    int choice;
    while((choice = menu(fileName, saveDataName)) != 7){
        switch(choice){
            case 1: AddData(dataFile);      break;
            case 2: UpdateData(dataFile);   break;
            case 3: DeleteData(dataFile);   break;
            case 4: PrintData();            break;
            case 5: Import(dataFile);       break;
            case 6: Export(fileName);       break;
            case 7: return 0;
            default:
                puts("\nPlease choose existing choice.");
            break;
        }   
    }
}

void AddData(FILE *file){
    int x;
    char sindex[3];
    
    char _NIM[8];
    char _name[20];
    char _gender[10];
    float _ipk;
    
    printf("Masukkan NIM    : "); scanf(" %[^\n]", _NIM     );
    printf("Masukkan nama   : "); scanf(" %[^\n]", _name    );
    printf("Masukkan gender : "); scanf(" %[^\n]", _gender  );
    printf("Masukkan IPK    : "); scanf(" %f"    , &_ipk     );
    
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    x = atoi(sindex) - 1; //get index from NIM
    
    strcpy(siswa[x].NIM,  _NIM      );
    strcpy(siswa[x].name, _name     );
    strcpy(siswa[x].jk,   _gender   );
    siswa[x].IPK = _ipk;
    
    fseek (file, x * sizeof(mahasiswa), SEEK_SET);
    fwrite(&siswa[x], sizeof(mahasiswa), 1, file);
    fclose(file);
}


void UpdateData(FILE* file){
    int x, finish = 0;
    char sindex[3];
    
    char _NIM[8];
    char nChange[20];
    float fChange;
    
    PrintData();
    
    printf("============Edit============\nMasukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    x = atoi(sindex) - 1; //get index from NIM
    
    int c;
    printf("%-9s%-21s%-11s%-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    printf("%-9.8s%-21.20s%-11.10s%-5.2f\n", 
        siswa[x].NIM, siswa[x].name, siswa[x].jk, siswa[x].IPK);
        
    if(!strcmp(siswa[x].NIM, "")){
        printf("Cannot find student with that NIM.\n");
    }else{
        printf("%s\n%s\n>> ", "1. Nama", "2. IPK"); scanf("%d", &c);
        do{
            switch(c){
                case 1:
                    printf("Enter new name : "); scanf(" %[^\n]", nChange);
                    strcpy(siswa[x].name, nChange);
                    finish = 1;
                break;
                case 2:
                    printf("Enter new IPK  : "); scanf(" %f", &fChange);
                    siswa[x].IPK = fChange;
                    finish = 1;
                break;
                default:
                break;
            }  
        }while(finish == 0);
    }
    
    fseek (file, x * sizeof(mahasiswa), SEEK_SET);
    fwrite(&siswa[x], sizeof(mahasiswa), 1, file);
    fclose(file);
    
    printf("\nEdit Complete ...\n");
}

void DeleteData(FILE *file){
    int x;
    char sindex[3];
    
    char _NIM[8];
    
    PrintData();
    
    printf("===========Delete===========\nMasukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    x = atoi(sindex); //get index from NIM
    
    strcpy(siswa[x].NIM,  "");
    strcpy(siswa[x].name, "");
    strcpy(siswa[x].jk,   "");
    siswa[x].IPK = 0;
    
    printf("%-9.8s%-21.20s%-11.10s%-5.2f\n", 
                siswa[x].NIM, siswa[x].name, siswa[x].jk, siswa[x].IPK);
    
    fseek (file, x * sizeof(mahasiswa), SEEK_SET);
    fwrite(&siswa[x], sizeof(mahasiswa), 1, file);
    fclose(file);
    
    printf("\nDelete Complete ...\n");
}

void PrintData(){
    printf("============Data============");
    printf("\n%-9s%-21s%-11s %-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i = 0; i < MHSCOUNT; i++){
        if(strcmp(siswa[i].NIM, ""))
            printf("%-9.8s%-21.20s%-11.10s%-5.2f\n", 
                siswa[i].NIM, siswa[i].name, siswa[i].jk, siswa[i].IPK);
    }
}

void Import(FILE* file){
    if(file == NULL){
        printf("File cannot be opened.");
        return;
    }else{
        rewind(file);
        for(int i = 0; i < MHSCOUNT; i++){
            fseek (file, i * sizeof(mahasiswa), SEEK_SET);
            fread(&siswa[i], sizeof(mahasiswa), 1, file);
        }   
    }
    printf("\nImport Complete ...\n");
    fclose(file);
}

void Export(char file[]){
    FILE* filePtr = fopen(file, "w");
    fprintf(filePtr, "%-9s%-21s%-11s %-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i = 0; i < MHSCOUNT; i++){
        if(strcmp(siswa[i].NIM, ""))
            fprintf(filePtr, "%-9.8s%-21.20s%-11.10s%-5.2f\n", 
                siswa[i].NIM, siswa[i].name, siswa[i].jk, siswa[i].IPK);
    }
    printf("\nExport Complete ...\n");
    fclose(filePtr);
}

int menu(char fileName[], char saveDataName[]){
    int c;
    printf("%s\n%s\n%s\n%s\n%s\n%s%s\n%s%s\n%s\n>> ",
    "============Menu============",
    "1. Add Data",
    "2. Update Data",
    "3. Delete Data",
    "4. Print Data",
    "5. Import Data from ", saveDataName,
    "6. Export Data to ", fileName,
    "7. Exit");
    scanf("%d", &c);
    return c;
}
