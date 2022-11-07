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
        
        printf("%d", strcmp(player.name, " ")==0);
        if(strcmp(player.name, " ")==0){
            Start(&player);
            printf("%s\n|Name\t: %-15s|\n|HP\t: %-15d|\n|ATK\t: %-15d|\n|DEF\t: %-15d|\n|EQ \t: %-15s|\n|\t- %-15s|\n|\t- %-15s|\n|\t- %-15s|\n%s", 
                "+------------------------+",
                player.name, player.hp, player.atk, player.armor, "", player.eq[Weapon]->name, player.eq[Shield]->name, player.eq[Armor]->name,
                "+------------------------+"); 
            Save(PlayerSaveFile, player);   
        }else{
            printf("%s\n|Name\t: %-15s|\n|HP\t: %-15d|\n|ATK\t: %-15d|\n|DEF\t: %-15d|\n|EQ \t: %-15s|\n|\t- %-15s|\n|\t- %-15s|\n|\t- %-15s|\n%s", 
                "+------------------------+",
                player.name, player.hp, player.atk, player.armor, "", player.eq[Weapon]->name, player.eq[Shield]->name, player.eq[Armor]->name,
                "+------------------------+");
        }
    }
    fclose(PlayerSaveFile);
}

void Start(Player *p){
    char charName[12];
    Equipment startingEq1 = { "Stick", 1, 0, 0 };
    Equipment startingEq2 = { "Shield", 0, 1, 1 };
    Equipment startingEq3 = { "Armor", 0, 2, 2 };
    puts("Enter your character name (Max. 12 Character) : ");
    scanf("%[^\n]s", charName);
    strcpy(p->name, charName);
    p->hp           = 5;
    p->atk          = 2;
    p->armor        = 0;
    p->eq[Weapon]   = &startingEq1;
    p->eq[Shield]   = &startingEq2;
    p->eq[Armor]    = &startingEq3;
}

void Save(FILE *file, Player p){
    rewind(file);

    fwrite(&p, sizeof(p), 1, file);
}
