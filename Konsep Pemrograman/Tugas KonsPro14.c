#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum JenisKelamin { Pria, Wanita };

typedef struct{
    char NIM[8];
    char nama[20];
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
        dataFile = fopen(fileName, "wb+");
    }
    
    switch(menu()){
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
    
    printf("Masukkan NIM    : "); scanf("%s", _NIM);
    printf("Masukkan name   : "); scanf("%s", _name);
    printf("Masukkan gender : "); scanf("%s", _gender);
    printf("Masukkan IPK    : "); scanf("%f", &_ipk);
    
    strcpy(mhs.NIM, _NIM);
    strcpy(mhs.nama, _name);
    mhs.IPK = _ipk;
    
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[6 + i]; //get the last three digit from NIM
    index = atoi(sindex); //get index from NIM
    
    if(strcmp(_gender, "Laki-Laki") || strcmp(_gender, "laki-laki") 
        || strcmp(_gender, "Pria") || strcmp(_gender, "pria")){
        mhs.jk = 1; //Woman
    }else if(strcmp(_gender, "Perempuan") || strcmp(_gender, "perempuan") 
        || strcmp(_gender, "Wanita") || strcmp(_gender, "wanita")){
        mhs.jk = 0; //Man
    }
    
    rewind(file);
    fwrite(&mhs, index * sizeof(mahasiswa), 1, file);
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
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n>> ",
    "============Menu============",
    "1. Add Data",
    "2. Update Data",
    "3. Delete Data",
    "4. Print Data",
    "5. Import Data from File",
    "6. Export Data to File");
    scanf("%d", &c);
    return c;
}
