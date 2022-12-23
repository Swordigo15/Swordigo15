#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MHSCOUNT 10

typedef struct{
    char NIM[10];
    char name[20];
    char jk[10];
    float IPK;
}mahasiswa;

void AddData    (FILE*);
void UpdateData (FILE*);
void DeleteData ();
void PrintData  ();
void Import     (FILE*);
void Export     (char[]);

int menu();

mahasiswa* siswa[MHSCOUNT];

int main()
{
    FILE* dataFile = NULL;
    
    char fileName[15];
    printf("Enter file Name : "); scanf("%s", fileName); strcat(fileName, ".txt");
    
    if((dataFile = fopen("SaveData.txt", "rb+")) == NULL){
        dataFile = fopen("SaveData.txt", "wb+");
    }
    
    int choice;
    while((choice = menu()) != 7){
        switch(choice){
            case 1: AddData(dataFile);      break;
            case 2: UpdateData(dataFile);   break;
            case 3: DeleteData();           break;
            case 4: PrintData();            break;
            case 5: Import("SaveData.txt"); break;
            case 6: Export(fileName);       break;
            case 7: return 0;
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
    char _gender[10];
    float _ipk;
    
    printf("Masukkan NIM    : "); scanf(" %s"    , _NIM);
    printf("Masukkan nama   : "); scanf(" %[^\n]", _name);
    printf("Masukkan gender : "); scanf(" %[^\n]", _gender);
    printf("Masukkan IPK    : "); scanf(" %f"    , &_ipk);
    
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    index = atoi(sindex) - 1; //get index from NIM
    
    strcpy(siswa[index].NIM,  _NIM);
    strcpy(siswa[index].name, _name);
    strcpy(siswa[index].jk,   _gender);
    siswa[index].IPK = _ipk;
    
    fseek(file, (index - 1) * sizeof(mahasiswa), SEEK_SET);
    fwrite(&siswa[index], sizeof(mahasiswa), 1, file);
    fclose(file);
}


void UpdateData(FILE* file){
    int x;
    char sindex[3];
    
    char _NIM[8];
    
    PrintData();
    
    printf("============Edit============\nMasukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    x = atoi(sindex) - 1; //get index from NIM
    
    int c;
    printf("%-9s%-21s%-11s%-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    printf("%-9s%-21s%-11s%-5.2f\n", 
        siswa[x].NIM, siswa[x].name, siswa[x].jk, siswa[x].IPK);
        
    if(!strcmp(siswa[x].NIM, "")){
        
    }else{
       printf("%s\n%s\n>> ", "1. Nama", "2. IPK"); scanf("%d", &c);
        switch(c){
            case 1:
            break;
            case 2:
            break;
            default:
            break;
        } 
    }
}

void DeleteData(){
    int x;
    char sindex[3];
    
    char _NIM[8];
    
    mahasiswa mhsTemp = { "", "", "", 0 };
    
    PrintData();
    
    printf("===========Delete===========\nMasukkan NIM    : "); scanf(" %8[^\n]" , _NIM);
    for(int i = 0; i < 3; i++) sindex[i] = _NIM[5 + i]; //get the last three digit from NIM
    x = atoi(sindex); //get index from NIM
    
    strcpy(siswa[x].NIM,  mhsTemp.NIM);
    strcpy(siswa[x].name, mhsTemp.name);
    strcpy(siswa[x].jk,   mhsTemp.jk);
    siswa[x].IPK = mhsTemp.IPK;
    
    printf("Delete Complete ...");
}

void PrintData(){
    printf("%-9s%-21s%-11s %-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i = 0; i < MHSCOUNT; i++){
        if(strcmp(siswa[i].NIM, ""))
            printf("%-9.8s%-21.20s%-11.10s%-5.2f\n", 
                siswa[i].NIM, siswa[i].name, siswa[i].jk, siswa[i].IPK);
    }
}

void Import(FILE* file){
    file = fopen("SaveData.txt", "rb+");
    rewind(file);
    for(int i = 0; i < MHSCOUNT; i++){
        fread(&siswa[i], sizeof(mahasiswa), 1, file);
    }
    fclose(file);
}

void Export(char file[]){
    FILE* filePtr = fopen(file, "w");
    fprintf(filePtr, "%-9s%-21s%-11s %-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i = 0; i < MHSCOUNT; i++){
        if(strcmp(siswa[i].NIM, ""))
            fprintf(filePtr, "%-9.8s%-21.20s%-11.10s%-5g\n", 
                siswa[i].NIM, siswa[i].name, siswa[i].jk, siswa[i].IPK);
    }
    fclose(filePtr);
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
