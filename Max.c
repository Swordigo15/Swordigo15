#include <stdio.h>

int Max(int, int, int);

int main()
{
    printf("%d", Max(1, 2, 3));

    return 0;
}

int Max(int i, int j, int k){
    if(i > j){
        if(i > k){
            return i;
        }else{
            return k;
        }
    }else{
        if(j > k){
            return j;
        }else{
            return k;
        }
    }
}
