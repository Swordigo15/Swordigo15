#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[10];
    char date[11];
    char time[10];
}SaveData;

int DisplaySaveDataList(FILE*, SaveData*);
void WriteSaveData(FILE*, SaveData, int);
void CreateNewSaveData(FILE*, SaveData*);
void LoadSaveData(FILE*, SaveData);

int main()
{
    FILE *fileList;
    FILE *saveFile;
    SaveData saveData[3];
    
    if((fileList = fopen("List.dat", "rb+")) == NULL){
        printf("File cannot be found.");
    }else{
        int c = DisplaySaveDataList(fileList, saveData);
        if(strcmp(saveData[c].name, "")){
            LoadSaveData(saveFile, saveData[c]);
        }else{
            CreateNewSaveData(saveFile, &saveData[c]);
            WriteSaveData(fileList, saveData[c], c);   
        }
    }
}

int DisplaySaveDataList(FILE *file, SaveData *sd){
    for(int i = 0; i < 3; ++i){
        fseek(file, i * sizeof(SaveData), SEEK_SET);
        fread(&sd[i], sizeof(SaveData), 1, file);
        
        printf("%d. ", i + 1);
        if(!strcmp(sd[i].name, "")){
            printf("New Save Data\n"); 
        }else{
            printf("%s %s %s\n", sd[i].name, sd[i].date, sd[i].time);
        }
    }
    int c;
    scanf("%d", &c); return c - 1;
}

void WriteSaveData(FILE *file, SaveData sd, int i){
    fseek(file, i * sizeof(SaveData), SEEK_SET);
    fwrite(&sd, sizeof(SaveData), 1, file);
}

void CreateNewSaveData(FILE *sf, SaveData *data){
    char fileName[10];
    printf("Enter file name : "); scanf("%s", name);
    sf = fopen(name, "wb+");
    strcpy(data->name, name);
    strcpy(data->date, __DATE__);
    strcpy(data->time, __TIME__);
}

void LoadSaveData(FILE *sf, SaveData data){
    sf = fopen(data.name, "rb+");
    printf("%s loaded", data.name);
}
