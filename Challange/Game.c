#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Save.h"

#define EAmount 10

#define Random(min, max)  ((min) + (rand() % (max)))

enum EquipmentType { Weapon, Shield, Armor };
enum PlayerC { Attack = 1, Heal, Defense, Flee, DisplayStats };

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

typedef struct{
    char name[15];
    int hp;
    int atk;
    int armor;
    int exp;
    float chanceAppear;
}Enemy;

Enemy enemyList[EAmount] = {
    {"Skelton", 3, 1, 0, 2, 0.2},           {"Zombie", 2, 2, 0, 2, 0.2},
    {"Slime", 5, 1, 0, 2, 0.2},             {"Armored Skelton", 3, 2, 1, 3, 0.075},
    {"Armored Zombie", 4, 2, 1, 3, 0.075},  {"Knight", 6, 2, 2, 5, 0.1},
    {"Ultra Slime", 8, 2, 3, 10, 0.075},    {"Dark Knight", 10, 3, 2, 12, 0.064},
    {"Dragon", 20, 5, 4, 20, 0.01},         {"???", 99, 99, 99, 10000, 0.001}
};

void Start(Stats*);
void PrintStats(Stats);
void PrintEnemy(Enemy);

void LevelUp(Stats*);
int PlayerChoice();
int GetEnemy(Stats);
void PlayerHPMod(Stats*, int, int);
void EnemyHPMod(Enemy*, int, int);

void Save (FILE*, Stats);

int main(){
    FILE *PlayerSaveFile = NULL;
    FILE *SaveDataList = NULL;

    Stats player;
    Enemy currEnemy;

    //ChooseSaveData(PlayerSaveFile, SaveDataList);

    if((PlayerSaveFile = fopen("A", "rb+")) == NULL){
        puts("File can't be found.");
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

    int choice = 0, playerTurn = 1, isDef = 0;
    ChooseE:
        currEnemy = enemyList[GetEnemy(player)];

        Play:
            while(playerTurn){
                PrintEnemy(currEnemy);
                choice = PlayerChoice();
                switch(choice){
                    case Attack:
                        EnemyHPMod(&currEnemy, player.atk, 0);
                        if(currEnemy.hp <= 0){
                            printf("%s is dead. You get %d exp.", currEnemy.name, currEnemy.exp); getchar(); getchar();
                            player.currentEXP += currEnemy.exp;
                            if(player.currentEXP >= player.EXP) LevelUp(&player);
                            printf("\e[1;1H\e[2J");
                            goto ChooseE;
                        }else{
                            playerTurn = 0;
                        }
                    break;
                    case Heal:
                        PlayerHPMod(&player, 3, 1);
                        playerTurn = 0;
                    break;
                    case Defense:
                        player.armor += 2;
                        isDef = 1;
                        playerTurn = 0;
                    break;
                    case Flee:
                        goto ChooseE;
                    break;
                    case DisplayStats:
                        printf("\e[1;1H\e[2J");
                        PrintStats(player);
                    break;
                }
            }
            PlayerHPMod(&player, currEnemy.atk, 0);
            if(isDef) player.armor -= 2;
            playerTurn = 1;
            printf("\e[1;1H\e[2J");
            goto Play;
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
    printf("You are lv.%d now.\n", player->lv); getchar();
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

void PrintEnemy(Enemy eStat){
    printf("\n%s\n|Name\t: %-16s|\n|HP\t: %-16d|\n|ATK\t: %-16d|\n|DEF\t: %-16d|\n%s",
            "+-------------------------+",
            eStat.name, eStat.hp, eStat.atk, eStat.armor,
            "+-------------------------+");
}

int PlayerChoice(){
    printf("\n|%-13s%-12s|\n|%-13s%-12s|\n|%-25s|\n%s\n",
           "1.Attack", "3.Defense",
           "2.Heal", "4.Flee",
           "5.Display Stats",
           "+-------------------------+");

    int c;
    printf("|>> "); scanf("%d", &c);
    return c;
}

int GetEnemy(Stats p){
    float totalChance;
    float r;
    if(p.lv < 10){
        r = Random(1, p.lv * 100);
    }else if(p.lv < 50){
        r = Random(p.lv * 10, 1000);
    }else{
        r = Random(500, 1000);
    }
    r /= 1000;

    for(int i = 0; i < EAmount; i++){
        totalChance += enemyList[i].chanceAppear;
        if(r - totalChance <= 0){
            return i;
        }
    }
    return 0;
}

void PlayerHPMod(Stats *player, int amount, int isHeal){
    if(isHeal){
        player->hp += amount;
        printf("%s heal %d hp\n", player->name, amount);
    }else{
        amount -= player->armor;
        if(amount <= 0) amount = 0;
        player->hp -= amount;
        printf("%s take %d damage\n", player->name, amount);
    }
    printf("Press any key to continue...\n"); getchar();
}

void EnemyHPMod(Enemy *enemy, int amount, int isHeal){
    if(isHeal){
        enemy->hp += amount;
        printf("%s heal %d hp\n", enemy->name, amount);
    }else{
        amount -= enemy->armor;
        if(amount <= 0) amount = 0;
        enemy->hp -= amount;
        printf("%s take %d damage\n", enemy->name, amount);
    }
    //printf("Press any key to continue..."); getchar();
}

void Save(FILE *file, Stats p){
    rewind(file);

    fwrite(&p, sizeof(p), 1, file);
}
