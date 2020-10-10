#include <stdio.h>

#define MAX_STU_NUM 5
#define NUM_SUBJECT 3

int main()
{
    char* sub[NUM_SUBJECT] = { "국어", "수학", "영어" };
    int total_stu[MAX_STU_NUM] = { 0 };
    int total_sub[NUM_SUBJECT] = { 0 };

    int i, j;
    int sum = 0;
    int avg = 0;

    int score_table[MAX_STU_NUM][NUM_SUBJECT] = {
        {80,60,90},
        {95,77,80},
        {40,30,55},
        {10,14,20},
        {42,30,66}
    };

    for (i = 0; i < MAX_STU_NUM; i++) {
        for (j = 0; j < NUM_SUBJECT; j++) {
            total_stu[i] += score_table[i][j];
            total_sub[j] += score_table[i][j];
        }
    }
    
    printf("\t국어 영어 수학\t\t총점  평균\n");

    for (int i = 0; i < MAX_STU_NUM; i++) {
        printf("%d번\t", i + 1);
        for (int j = 0; j < NUM_SUBJECT; j++) {
            printf("%d    ", score_table[i][j]);
        }
        printf("|");
        printf("\t%d\t%d\n", total_stu[i], total_stu[i] / NUM_SUBJECT);
    }
       
    printf("--------------------------------------------\n");

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            printf("총점  ");
            for (j = 0; j < NUM_SUBJECT; j++) {
                printf("%d  ", total_sub[j]);
            }
        }
        else {
            printf("평균  ");
            for (j = 0; j < NUM_SUBJECT; j++) {
                printf("%d  ", total_sub[j] / MAX_STU_NUM);
            }
        }
    }
    printf("     |");

    return 0;
}