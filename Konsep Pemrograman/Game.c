#include <stdio.h>
#include <string.h>

enum EquipmentType { Armor = 1, Shield, Weapon };

typedef struct{
    char name[12];
    int atk;
    int def;
    enum EquipmentType *eqType;
}Equipment;

typedef struct{
    char name[12];
    int hp;
    int atk;
    int armor;
    Equipment *eq[3];
}Player, Enemy;

void Start(Player*);
void Save (FILE*, Player);

int main () {
    FILE *PlayerSaveFile;
    
    Player player;
    
    if((PlayerSaveFile = fopen("SaveFile.dat", "rb+")) == NULL){
        puts("\"SaveFile.dat\" can't be found.");
        return 0;
    }else{
        fread(&player, sizeof(player), 1, PlayerSaveFile);
        
        if(!(strcmp(player.name, "") == 0)){
            Start(&player);
            printf("%s\n|Name\t: %-15s|\n|HP\t: %-15d|\n|ATK\t: %-15d|\n|DEF\t: %-15d|\n%s", 
                "+------------------------+",
                player.name, player.hp, player.atk, player.armor,
                "+------------------------+");
            Save(PlayerSaveFile, player);   
        }else{
            printf("%s\n|%-24s|\n|Name\t: %-15s|\n|HP\t: %-15d|\n|ATK\t: %-15d|\n|DEF\t: %-15d|\n%s", 
                "+------------------------+", "Saved Data",
                player.name, player.hp, player.atk, player.armor,
                "+------------------------+");
        }
    }
    fclose(PlayerSaveFile);
}

void Start(Player *p){
    char charName[12];
    Equipment startingEq = { "Stick", 1, 0,  Weapon };
    puts("Enter your character name (Max. 12 Character) : ");
    scanf("%[^\n]s", charName);
    strcpy(p->name, charName);
    p->hp       = 5;
    p->atk      = 2;
    p->armor    = 0;
    p->eq[0]    = &startingEq;
}

void getStats(){
    
}

void Save(FILE *file, Player p){
    rewind(file);

    fwrite(&p, sizeof(p), 1, file);
}
