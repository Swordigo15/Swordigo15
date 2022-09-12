#include <stdio.h>

int Max(int, int, int);

int main()
{
    int i, j, k;
    printf("Angka 1 : "); scanf("%d", &i);
    printf("Angka 2 : "); scanf("%d", &j);
    printf("Angka 3 : "); scanf("%d", &k);
    printf("%d", Max(i, j, k));

    return 0;
}

int Max(int i, int j, int k){
    if(i > j){
        if(i > k){
            return i;
        }
        else{
            return k;
        }
    }else{
        if(j > k){
            return j;
        }
        else{
            return k;
        }
    }
}
