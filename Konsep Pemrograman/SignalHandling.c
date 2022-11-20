#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void Enter();

int main()
{   
    int x;
    
    signal(SIGABRT, Enter);
    signal(SIGFPE, Enter);
    signal(SIGILL, Enter);
    signal(SIGINT, Enter);
    signal(SIGSEGV, Enter);
    signal(SIGTERM, Enter);
    srand(time(NULL));
    while(1){
        x = (rand() % 9);
        printf("%d ", x);
        switch(x){
            case 1:
                raise(SIGABRT); //6
            break;
            case 2:
                raise(SIGFPE); //8
            break;
            case 3:
                raise(SIGILL); //4
            break;
            case 4:
                raise(SIGINT); //2
            break;
            case 5:
                raise(SIGSEGV); //11
            break;
            case 6:
                raise(SIGTERM); //15
            break;
        }
    }
}

void Enter(int x)
{
    printf("signal %d", x); getchar();
}
