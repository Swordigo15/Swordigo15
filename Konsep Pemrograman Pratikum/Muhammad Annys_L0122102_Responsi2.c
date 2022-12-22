#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MHSCOUNT 10

typedef struct{
    char NIM[9];
    char name[20];
    char jk[10];
    float IPK;
}mahasiswa;

void AddData(FILE*);
void UpdateData(FILE*)
void PrintData(mahasiswa[]);

int menu();

int main()
{
    FILE* dataFile = NULL;
    mahasiswa siswa[MHSCOUNT];
    
    char fileName[15];
    printf("Enter file Name : "); scanf("%s", fileName);
    
    if((dataFile = fopen(fileName, "rb+")) == NULL){
        dataFile = fopen(fileName, "wb+");
    }
    
    int choice;
    while((choice = menu()) != 7){
        switch(choice){
            case 1: AddData(dataFile); break;
            case 2: UpdateData(dataFile); break;
            case 3:
            break;
            case 4: PrintData(siswa); break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            default:
            break;
        }   
    }
}

void AddData(FILE *file){
    int index;
    char sindex[3];
    
    char _NIM[8];
    char _name[20];
    char _gender[10]; int gndr = 0;
    float _ipk;
    
    mahasiswa mhs = { "", "", "", 0};
    
    printf("Masukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    printf("Masukkan nama   : "); scanf(" %20[^\n]", _name);
    printf("Masukkan gender : "); scanf(" %10[^\n]", _gender);
    printf("Masukkan IPK    : "); scanf(" %f"      , &_ipk);
    
    strcpy(mhs.NIM, _NIM);
    strcpy(mhs.name, _name);
    strcpy(mhs.jk, _gender);
    mhs.IPK = _ipk;
    
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    index = atoi(sindex); //get index from NIM
    
    printf("%d\n%f\n", index, mhs.IPK);
    
    fseek(file, (index - 1) * sizeof(mahasiswa), SEEK_SET);
    fwrite(&mhs, sizeof(mahasiswa), 1, file);
}


void UpdateData(FILE* file){
    int index;
    char sindex[3];
    
    char _NIM[8];
    printf("============Edit============\nMasukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    index = atoi(sindex); //get index from NIM
}


void PrintData(mahasiswa mhs[]){
    printf("%-10s %-20s\t\t %-11s %-4s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i = 0; i < MHSCOUNT; i++)printf("%-10s %-20s\t\t %-11s %-4f\n", mhs[i].NIM, mhs[i].name, mhs[i].jk, mhs[i].IPK);
}
/*
void Save(FILE *file){
    rewind(file);
    for(int i = 0; i < 6; i++) fwrite(&signals[i], sizeof(SIG), 1, file);
    puts("Data has been saved.");
}
void Load(FILE *file){
    rewind(file);
    for(int i = 0; i < 6; i++) fread(&signals[i], sizeof(SIG), 1, file);    
    puts("Data has been loaded.");
}
*/

int menu(){
    int c;
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n>> ",
    "============Menu============",
    "1. Add Data",
    "2. Update Data",
    "3. Delete Data",
    "4. Print Data",
    "5. Import Data from File",
    "6. Export Data to File",
    "7. Exit");
    scanf("%d", &c);
    return c;
}
