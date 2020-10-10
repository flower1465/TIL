#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct _person {
    char szName[10];
    int age;
}p1;


int main()
{
    struct _person *p;
    struct _person p1 = { "박승준", 17 };
    p = &p1;

    //p = malloc(sizeof(int));

    printf("%s %d\n", p -> szName, p -> age);

    //free(p);

    return 0;
}