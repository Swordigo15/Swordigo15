#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/******************************/
//Prototype Function
void Welcome();
void Login();
void ChooseClass(int[]);

void DisplayStats(int, int[]);

void GetEXP(int, int);
void LevelUp();
void TakeDamage(char[], int[], int);
void Heal(char[], int[], int);

void EnemyTurn();

int Random(int, int);
/******************************/

/******************************/
//Variable
//  char
char playerName[10];
char titleName[20];
char classList[3][10] = {"Knight", "Archer", "Mage"};

char enemyList[3][20] = {"Skeleton", "Zombie", "Slime"};

//  int
int level = 1, skillPoint = 5;
int myExp = 1, maxExp = 100;
int c;

//  other
time_t t;
/******************************/

int main()
{
    srand((unsigned) time(&t));

    int playerStatsNum[3];
    int enemyStatsNum[3];
    int currentExp = (int)(myExp / maxExp);

    Welcome();
    Login();
    ChooseClass(playerStatsNum);
    DisplayStats(currentExp, playerStatsNum);

    while(getchar() != EOF){
        system("cls");
        int q;
        static char eName[20];
        strcpy(eName, enemyList[Random(0, 2)]);
        enemyStatsNum[0] = Random(1, 5);
        enemyStatsNum[1] = Random(1, 2);
        enemyStatsNum[2] = Random(0, 1);

        char f;
        printf("A %s has appeared.\n\n", eName);
        printf("Fight? (y/n) "); scanf("%s", &f);

        do{
            system("cls");
            printf("%s\n", eName);
            printf("|-----------------------------|\n");
            printf("|HP  : %d   ATK : %d    |\n\n", enemyStatsNum[0], enemyStatsNum[1]);

            printf("%s Lv.%d", titleName, level);
            printf("|-------------------------|\n");
            printf("|HP  : %d   ATK : %d    |\n", playerStatsNum[0], playerStatsNum[1]);

              puts("[1] Slash  (deal damage equal to ATK stat)");
              puts("[2] Heal   (heal 1 health point)");
              puts("[3] Flee   (run from enemy)");

            printf("Choice : "); scanf("%d", &q);

            switch(q){
                case 1:
                    TakeDamage(eName, playerStatsNum, playerStatsNum[2]);
                    EnemyTurn(enemyStatsNum, playerStatsNum);
                    break;
                case 2:
                    Heal(playerName, playerStatsNum, 1);
                    EnemyTurn(enemyStatsNum, playerStatsNum);
                    break;
                case 3:
                    goto end;
                    break;
                default:
                    break;
            }
            end:
                continue;
        }while(enemyStatsNum[0] > 0);
    }
}

void Welcome(){ //Function untuk memunculkan kata welcome
    //Welcome Sign
    puts("__      __      __  _____   _        ______    ______    ___    ___   _____ ");
    puts("\\ \\    /  \\    / / |  ___| | |      / ____ \\  / ____ \\  |   \\  /   | |  ___|");
    puts(" \\ \\  / /\\ \\  / /  | |___  | |     | |    \\/ | |    | | | |\\ \\/ /| | | |___ ");
    puts("  \\ \\/ /  \\ \\/ /   |  ___| | |     | |       | |    | | | | \\__/ | | |  ___|");
    puts("   \\  /    \\  /    | |___  | |___  | |____/\\ | |____| | | |      | | | |___ ");
    puts("    \\/      \\/     |_____| |_____|  \\______/  \\______/  |_|      |_| |_____|");
}

void Login(){//Function untuk memasukkan nama pemain
      puts("");
      puts("(Max 10 character)");
    printf("Enter player Name : "); scanf("%s", playerName);
}

void ChooseClass(int s[]){//Function

    char choice[10];

    printf("\nHello, %s\n", playerName);
      puts("Choose your class: ");
    for(int i = 0; i < 3; i++){
        printf("  %d. %s\n", i + 1, classList[i]);//Still broken fix it later!!!
    }

    printf("Your class is "); scanf("%s", choice);
    if(!strcmp(choice, "Knight") || !strcmp(choice, "knight") || !strcmp(choice, "1")){
        s[0] = 3; s[1] = 2; s[2] = 3; s[3] = 2;
        sprintf(titleName, "\n\tKnight %s\n", playerName);
    }else if(!strcmp(choice, "Archer") || !strcmp(choice, "archer") || !strcmp(choice, "2")){
        s[0] = 2; s[1] = 3; s[2] = 0; s[3] = 3;
        sprintf(titleName, "\n\tArcher %s\n", playerName);
    }else if(!strcmp(choice, "Mage") || !strcmp(choice, "mage") || !strcmp(choice, "3")){
        s[0] = 2; s[1] = 4; s[2] = 1; s[3] = 1;
        sprintf(titleName, "\n\tMage %s\n", playerName);
    }
}

void DisplayStats(int e, int s[]){

    addMore:
        system("cls");
        printf("       %s", titleName);
        printf("\n|Lv. %d             SP : %d |\n", level, skillPoint);
        printf("|-------------------------|\n");
        printf("|[1]HP  : %d         |\n", s[0]);
        printf("|[2]ATK : %d         |\n", s[1]);
        printf("|[3]DEF : %d         |\n", s[2]);
        printf("|----|---------------|\n");
        printf("|EXP |%d / %d        |\n", myExp, maxExp);
        printf("|----|---------------|\n");

        if(skillPoint <= 0){
            system("cls");
        }
        else{
          puts("Add your SP to your stats.\n");
          puts("(choose by inputing the number ");
          puts("in front of the stats or ");
          puts("choose [4] to stop adding)");
        printf("\nAdd to "); scanf("%d", &c);
        switch(c){
            case 1:
                s[0]++; skillPoint--;
                puts("HP +1");
                goto addMore;
                break;
            case 2:
                s[1]++; skillPoint--;
                puts("ATK +1");
                goto addMore;
                break;
            case 3:
                s[2]++; skillPoint--;
                puts("DEF +1");
                goto addMore;
                break;
            case 4:
                system("cls");
                break;
        }
    }
}

void EnemyTurn(int eStats[], int stats[]){
    int r = Random(0, 10);
    if(r >= 5){
        TakeDamage(playerName, stats, eStats[2]);
    }else{
        printf("Do Nothing\n");
    }

    char f;
    printf("Continue? (y) "); scanf("%s", &f);
}

void TakeDamage(char name[], int stats[], int damage){
    damage -= stats[2];
    if(damage <= 0)
        damage = 0;
    stats[0] -= damage;
    printf("%d %s takes %d damage\n", stats[1], name, damage);
}

void Heal(char name[], int stats[], int amount){
    stats[0] += amount;
    printf("%s heal %d health point\n", name, amount);
}

void GetEXP(int min, int max){
    myExp += Random(min, max);
    if(myExp >= maxExp)
        LevelUp();
}

void LevelUp(){
    level++;
    skillPoint++;
    myExp -= maxExp;
    maxExp += 20;
}

int Random(int min, int max){
    return min + (rand() % max);
}

//Nama file dan subjek : NIM_Nama panggilan_T03Modifikasi
/*
  > EX-OR dibuat dalam DSCH2 lalu screenshot
    dan taruh di ms word
  > Modifikasi NAND dan NOR (3 masing-masing) di buat
    di DSCH2 lalu screenshot dan taruh di ms word
  kirim ke kuliah.ww@gmail.com
*/
