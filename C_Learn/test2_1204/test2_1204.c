#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);

    if (score >= 90)
        printf("A");
    else if (score >= 80)
        printf("B");
    else if (score >= 70)
        printf("C");
    else if (score >= 60)
        printf("D");
    else if (score <= 60)
        printf("F");

    return 0;
}
