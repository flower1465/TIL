#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _person Person;

struct _person {
    int no;
    char name[11];
    int age;
};

int main()
{   

    Person P[5];
    Person* p;

    p = (struct _person*)malloc(sizeof(struct _person) * 5);


    return 0;
}
