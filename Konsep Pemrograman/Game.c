#include <stdio.h>
#include <string.h>

enum EquipmentType { Weapon, Shield, Armor };

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
    Equipment eq[3];
}Stats;

void Start(Stats*);
void PrintStats(Stats);

void Save (FILE*, Stats);

int main () {
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
        }
    }
    fclose(PlayerSaveFile);
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
    for(int i = 0; i < Armor; i++){
        p->atk  += p->eq[i].atk;
        p->armor  += p->eq[i].def;
    }
}

void PrintStats(Stats stat){
    printf("%s\n|Name\t: %-15s|\n|HP\t: %-15d|\n|ATK\t: %-15d|\n|DEF\t: %-15d|\n|EQ \t: %-15s|\n|\t- %-15s|\n|\t- %-15s|\n|\t- %-15s|\n%s", 
                "+------------------------+",
                stat.name, stat.hp, stat.atk, stat.armor,
                "", stat.eq[Weapon].name, stat.eq[Shield].name, stat.eq[Armor].name,
                "+------------------------+"); 
}

void Save(FILE *file, Stats p){
    rewind(file);

    fwrite(&p, sizeof(p), 1, file);
}
