#include <stdio.h>

enum JenisKelamin { Pria, Wanita };

typedef struct{
    char NIM[8];
    char nama[20];
    int jk;
    float IPK;
}mahasiswa;

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
        case 1:
        break;
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
    char _NIM[8];
    char _name[20];
    printf("Enter NIM  : "); scanf("%s", _NIM);
    printf("Enter name : "); scanf("%s", _name);
}

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
