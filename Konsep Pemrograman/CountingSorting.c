#include <stdio.h>

int main()
{
    int elemen[20], temp, x, n;
    printf("Masukkan banyak Element : "); scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Masukkan Bilangan ke-%d : ", i + 1); scanf("%d", &elemen[i]);
    }

    printf("\nSebelum di sorting : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", elemen[i]);
    }

    for(int i = 0; i < (n - 1); i++)
    {
        x = i;
        for(int j = i + 1; j < n; j++)
        {
            if(elemen[j] < elemen[x])
            {
                x = j;
            }
        }
        temp = elemen[i];
        elemen[i] = elemen[x];
        elemen[x] = temp;
    }

    printf("\nSetelah Sorting : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", elemen[i]);
    }
    printf("\n");
}
