#include <stdio.h>
#include <signal.h>

enum SIGS{ ABRT   = 1, FPE, ILL, INT, SEGV , TERM  };
enum MENU{ SIGNAL = 1, SAVE, READ, DISPLAY, UPDATE };

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

int main()
{
    FILE *studentList = NULL;
    
    signal(SIGABRT, Signaling);
    signal(SIGFPE , Signaling);
    signal(SIGILL , Signaling);
    signal(SIGINT , Signaling);
    signal(SIGSEGV, Signaling);
    signal(SIGTERM, Signaling);
    
    if((studentList = fopen("List", "rb+")) == NULL){
        printf("File cannot be found.");
    }else{
        int c;
        menu:
        switch(c = Menu()){
            case SIGNAL:
                SHMENU();
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
            "3. Read", 
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
    }
}

void Signaling(int n){
    printf("This is signal %d\n%s", n, "This signal is called when ");
    switch(n){
        case 2:
            printf("");
        break;
        case 4:
            
        break;
        case 6:
            
        break;
        case 8:
            
        break;
        case 11:
            
        break;
        case 15:
            
        break;
    }
}

void Save(){
    
}
