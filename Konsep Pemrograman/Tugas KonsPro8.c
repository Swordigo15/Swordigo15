#include <stdio.h>

typedef struct Student{
    char name[10];
    char NIM[8];
    unsigned int age;
}student;

union Grade{
    unsigned int exam[3];
    float *avg;
};

int main()
{
    student s;
    union Grade g;
    float total;
    
    scanf("%s", s.name);
    scanf("%s", s.NIM);
    scanf("%u", &s.age);
    scanf("%u", &g.exam[0]);
    scanf("%u", &g.exam[1]);
    scanf("%u", &g.exam[2]);
    
    total = (g.exam[0] + g.exam[0] + g.exam[0]) / 3;
    g.avg = &total;
    printf("\n%s%s\n%s%s\n%s%u%s\n%s%g",
    "Your name is ", s.name,
    "Your NIM is ", s.NIM,
    "And you are ", s.age, " years old.",
    "Your average is ", *g.avg);
    
}
