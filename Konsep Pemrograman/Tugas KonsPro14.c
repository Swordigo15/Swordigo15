#include <stdio.h>
#include <string.h>
#include <signal.h>

enum SIGS{ ABRT   = 1, FPE, ILL, INT, SEGV , TERM  };
enum MENU{ SIGNAL = 1, SAVE, LOAD, DISPLAY, UPDATE };

typedef struct{
    char name[8];
    int counter;
}SIG;

SIG signals[6] = {
    {"SIGABRT", 0}, {"SIGFPE",  0},
    {"SIGILL",  0}, {"SIGINT",  0},
    {"SIGSEGV", 0}, {"SIGTERM", 0},
};

int  Menu();
void SHMenu();
void Signaling();
void Save(FILE*);
void Load(FILE*);
void Display();
void Update(SIG*);

int main()
{
    FILE *signalList = NULL;
    
    signal(SIGABRT, Signaling);
    signal(SIGFPE , Signaling);
    signal(SIGILL , Signaling);
    signal(SIGINT , Signaling);
    signal(SIGSEGV, Signaling);
    signal(SIGTERM, Signaling);
    
    if((signalList = fopen("List", "rb+")) == NULL){
        printf("File cannot be found.");
    }else{
        int c;
        menu:
        switch(c = Menu()){
            case SIGNAL:
                SHMenu();
            break;
            case SAVE:
                Save(signalList);
            break;
            case LOAD:
                Load(signalList);
            break;
            case DISPLAY:
                Display();
            break;
            case UPDATE:
                Update(signals);
            break;
        }
        goto menu;
    }
}

int Menu(){
    int n;
    printf("%s\n%s\n%s\n%s\n%s\n%s", 
            "-----MENU-----",
            "1. Signal"
            "2. Save", 
            "3. LOAD", 
            "4. Display", 
            "5. Update", 
            ">> "); scanf("%d", &n);
    return n;
}

void SHMenu(){
    int n;
    printf("Call : %s\n%s\n%s\n%s\n%s\n%s\n%s", 
            "1. SIGABRT", 
            "2. SIGFPE", 
            "3. SIGILL",
            "4. SIGINT",
            "5. SIGSEGV",
            "6. SIGTERM",
            ">> ");
    scanf("%d", &n);
    switch(n){
        case ABRT:
            raise(SIGABRT);
        break;
        case FPE:
            raise(SIGFPE);
        break;
        case ILL:
            raise(SIGILL);
        break;
        case INT:
            raise(SIGINT);
        break;
        case SEGV:
            raise(SIGSEGV);
        break;
        case TERM:
            raise(SIGTERM);
        break;
        default:
        break;
    }
}

void Signaling(int n){
    printf("This is signal %d\n%s", n, "This signal is ");
    switch(n){
        case 2:
            printf("called when there is abnormal termination of the program.");
        break;
        case 4:
            printf("called when there is an erroneous arithmetic operation.");
        break;
        case 6:
            printf("called when there is detection of illegal instruction");
        break;
        case 8:
            printf("a receipt of an interactive attention signal");
        break;
        case 11:
            printf("called when there is an attempt to access to memory that is not allocated to a program");
        break;
        case 15:
            printf("called when there is a termination request sent to a program");
        break;
    }
}

void Save(FILE *file){
    for(int i = 0; i < 6; i++) fwrite(&signals[i], sizeof(SIG), 1, file);    
    puts("Data has been saved.");
}

void Load(FILE *file){
    for(int i = 0; i < 6; i++) fread(&signals[i], sizeof(SIG), 1, file);    
    puts("Data has been loaded.");
}

void Display(){
    for(int i = 0; i < 6; i++) printf("%d. %s called %d times\n", i+1, signals[i].name, signals[i].counter);
}

void Update(SIG *s){
    int n; char nTemp[8];
    Display();
    printf("\nChoose Signal you want to update    : "); scanf("%d",  &n);
    printf("Write new signal name (max. 7 char) : "); scanf("%s", nTemp);
    strcpy(s[n]->name, nTemp);
    s[n]->counter = 0;
}
