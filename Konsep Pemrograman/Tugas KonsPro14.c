#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum JenisKelamin { Pria, Wanita };

typedef struct{
    char NIM[8];
    char name[20];
    int jk;
    float IPK;
}mahasiswa;

void AddData(FILE*);

int menu();

int main()
{
    FILE* dataFile = NULL;
    mahasiswa siswa[10];
    
    char fileName[15];
    printf("Enter file Name : "); scanf("%s", fileName);
    
    if((dataFile = fopen(fileName, "rb+")) == NULL){
        //dataFile = fopen(fileName, "wb+"); dataFile = fopen(fileName, "rb+");
    }
    
    int choice;
    while((choice = menu()) != 7){
        switch(choice){
            case 1: AddData(dataFile); break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
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
    
    mahasiswa mhs = { "", "", 0, 0};
    
    printf("Masukkan NIM    : "); scanf(" %[^\n]s", _NIM);
    printf("Masukkan nama   : "); scanf(" %[^\n]s", _name);
    printf("Masukkan gender : "); scanf(" %[^\n]s", _gender);
    printf("Masukkan IPK    : "); scanf(" %f", &_ipk);
    
    strcpy(mhs.NIM, _NIM);
    strcpy(mhs.name, _name);
    mhs.IPK = _ipk;
    
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    index = atoi(sindex); //get index from NIM
    
    if(!strcmp(_gender, "Laki-Laki") || !strcmp(_gender, "laki-laki") 
        || !strcmp(_gender, "Pria") || !strcmp(_gender, "pria")){
        mhs.jk = 0; //Man
    }else if(!strcmp(_gender, "Perempuan") || !strcmp(_gender, "perempuan") 
        || !strcmp(_gender, "Wanita") || !strcmp(_gender, "wanita")){
        mhs.jk = 1; //Woman
    }
    
    printf("%d\n%d\n%f\n", index, mhs.jk, mhs.IPK);
    
    rewind(file);
    fwrite(&mhs, index * sizeof(mahasiswa), 1, file);
}


void UpdateData(FILE* file){
    printf("Masukkan NIM    : ");
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
