#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Grade {
    int num;
    char name[20];
    int korea;
    int math;
    int english;
};

int main()
{   
    struct Grade g1[5];
   
    int sum = 0;
    int avg = 0;
    int ksum = 0;
    int msum = 0;
    int esum = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d %s %d %d %d", &g1[i].num, &g1[i].name, &g1[i].korea, &g1[i].math, &g1[i].english);
    }

    for (int i = 0; i < 5; i++) {
        ksum += g1[i].korea;
        esum += g1[i].english;
        msum += g1[i].math;
    }

    ksum /= 5;
    esum /= 5;
    msum /= 5;

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        sum = g1[i].korea + g1[i].math + g1[i].english;
        avg = sum / 3;

        printf("학번:%d 이름:%s 합계점수:%d 평균점수:%d\n", g1[i].num, g1[i].name, sum, avg);
    }

    printf("------------------------------------\n\n");

    printf("국어과목평균점수: %d 수학과목평균점수: %d 영어과목평균점수: %d\n", ksum, msum, esum);


    return 0;
}