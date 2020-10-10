#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Person {
    char name[15];
    int tall;
    int weight;
};

int main()
{   
    struct Person p1[4];

    for (int i = 0; i < 4; i++) {
        scanf("%s %d %d", &p1[i].name, &p1[i].tall, &p1[i].weight);
    }

    printf("\n\n")

    for (int i = 3; i >= 0; i--) {
        printf("%s %d %d\n", p1[i].name, p1[i].tall, p1[i].weight);
    }

    return 0;
}
