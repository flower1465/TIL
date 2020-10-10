#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Save {
    int hello;
};

int main()
{
    struct Save s1[5];

    int max = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &s1[i].hello);
        if (s1[max].hello < s1[i].hello) {
            max = i;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("%d번 저축금액 : %d\n", i + 1, s1[i].hello);
    }

    printf("저축왕 : %d번 %d원\n", max + 1, s1[max].hello);

    return 0;
}