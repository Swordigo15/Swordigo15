#include <stdio.h>
#include <string.h>

enum EquipmentType { Weapon, Shield, Armor };

typedef struct{
    char fileName[10];
    char directory[100];
}fileSave[3];

typedef struct{
    char name[12];
    int atk;
    int def;
    enum EquipmentType eqType;
}Equipment;

typedef struct{
    char name[12];
    int hp;
    int atk;
    int armor;
    int lv;
    int currentEXP;
    int EXP;
    Equipment eq[3];
}Stats;

void ChooseSaveData();
void Start(Stats*);
void PrintStats(Stats);

void Save (FILE*, Stats);

int main(){
    FILE *PlayerSaveFile;
    
    Stats player;
    
    if((PlayerSaveFile = fopen("SaveFile.dat", "rb+")) == NULL){
        puts("\"SaveFile.dat\" can't be found.");
        return 0;
    }else{
        fread(&player, sizeof(player), 1, PlayerSaveFile);
        
        if(!strcmp(player.name, "")){
            Start(&player);
            PrintStats(player);
            Save(PlayerSaveFile, player);   
        }else{
            PrintStats(player);
            Save(PlayerSaveFile, player);  
        }
    }
    fclose(PlayerSaveFile);
}

void ChooseSaveData(){
    int c;
    for(int i = 0; i < 3; i++){
        printf("%d. ", i - 1); 
        if(!strcmp(fileSave[i].fileName, "")){
            printf("New Save Data")
        }else{
            printf("%s %s\n", fileSave[i].fileName, fileSave[i].fileName);  
        }        
    }
    printf(">"); scanf("%d", &c);
    
    CheckFile(c);
}

void CheckFile(int n){
    char nameTemp[10];
    if(!strcmp(fileSave[n].fileName, "")){
        printf("Name your save file "); scanf("%s", nameTemp);
        strcpy(fileSave[i].fileName, nameTemp);
    }else{
        
    }
}

void Start(Stats *p){
    char charName[12];
    Equipment startingEq1 = { "Stick", 1, 0, 0 };
    Equipment startingEq2 = { "Shield", 0, 1, 1 };
    Equipment startingEq3 = { "Armor", 0, 2, 2 };
    puts("Enter your character name (Max. 12 Character) : ");
    scanf("%[^\n]s", charName);
    strcpy(p->name, charName);
    p->eq[Weapon]   = startingEq1;
    p->eq[Shield]   = startingEq2;
    p->eq[Armor]    = startingEq3;
    p->hp           = 5;
    p->atk          = 2;
    p->armor        = 0;
    p->lv           = 1;
    p->currentEXP   = 0;
    p->EXP          = 10;
    for(int i = 0; i < Armor; i++){
        p->atk  += p->eq[i].atk;
        p->armor  += p->eq[i].def;
    }
}

void LevelUp(Stats *player){
    player->lv++;
    player->currentEXP -= player->EXP;
    player->EXP += 5 * player->lv;
}

void PrintStats(Stats stat){
    printf("%s\n|Name\t: %-15sLv.%-4d|\n|HP\t: %-22d|\n|ATK\t: %-22d|\n|DEF\t: %-22d|\n|EQ \t: %-22s|\n|\t- %-22s|\n|\t- %-22s|\n|\t- %-22s|\n%s", 
                "+-------------------------------+",
                stat.name, stat.lv, stat.hp, stat.atk, stat.armor,
                "", stat.eq[Weapon].name, stat.eq[Shield].name, stat.eq[Armor].name,
                "+-------------------------------+"); 
    printf("\n%-4d/ %-3d\n", stat.currentEXP, stat.EXP);
    for(int i = 0; i < (stat.currentEXP * 30) / stat.EXP; i++) printf("#");
}

void Save(FILE *file, Stats p){
    rewind(file);

    fwrite(&p, sizeof(p), 1, file);
}
