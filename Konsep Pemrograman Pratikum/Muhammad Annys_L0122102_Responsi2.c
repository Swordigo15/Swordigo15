#include <stdio.h>



typedef struct{
    char NIM[8];
    char nama[20];
    enum JenisKelamin { 
        Pria, 
        Wanita 
    };
    float IPK;
}

int main()
{
    printf("Hello World");

    return 0;
}

int menu(){
    int c;
    printf("%s\n%s\n%s\n%s\n%s\n%s\n>> ",
    "============Menu============",
    "1. Add Data",
    "2. Update Data",
    "3. Delete Data",
    "4. Print Data",
    "5. Import Data from File",
    "6. Export Data to File",);
    scanf("%d", &c);
    return c;
}
