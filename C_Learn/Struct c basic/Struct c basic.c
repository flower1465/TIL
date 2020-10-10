#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
    int nember;
    char name[22];
    char call_nember[22];
    char teacher[22];
}s1;

int main()
{   
    struct Student s1;

    scanf("%d %s %s %s", &s1.nember, s1.name, s1.call_nember, s1.teacher);

    printf("%d %s %s %s\n\n", s1.nember, s1.name, s1.call_nember, s1.teacher);


    return 0;
}
