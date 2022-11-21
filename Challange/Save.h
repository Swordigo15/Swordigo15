#include <stdio.h>
#include <stdlib.h>
//Still in test prossecess
#include <string.h>

typedef struct{
    char name[10];
    char date[10];
    char time[10];
}SaveData;

void CreateNewSaveData(FILE*, char*, SaveData);

int main()
{
    FILE *fileList;
    FILE *saveFile;
    SaveData saveData[3];
    
    char fileName[10];
    
    if((fileList = fopen("List", "rb+")) == NULL){
        printf("File cannot be found.");
    }else{
        int c;
        scanf("%d", &c);
        CreateNewSaveData(saveFile, fileName, SaveData[c]);
    }
}

void CreateNewSaveData(FILE *sf, char *name, SaveData *data){
    printf("Enter file name : "); scanf("%s", name);
    sf = fopen(name, "wb+");
    strcpy(data->name, name);
    strcpy(data->date, __DATE__);
    strcpy(data->time, __TIME__);
}
