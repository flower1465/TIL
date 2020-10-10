#include <stdio.h>
#define MAX_STU_NUM 6
#define NUM_SUBJECT 3

int main()
{
    int sum = 0;
    int avg = 0;
    int score_table[MAX_STU_NUM][NUM_SUBJECT] = { 
        {80,60,90}, 
        {95,77,80}, 
        {40,30,55}, 
        {10,14,20}, 
        {40,30,66}
    };


    printf("---학생별 총점 및 평균---\n");

    for (int i = 0; i < MAX_STU_NUM; i++) {
        sum = 0;
        for (int j = 0; j < NUM_SUBJECT; j++) {
            sum += score_table[i][j];
        }
        avg = sum / NUM_SUBJECT;
        printf("%d번 학생- 총점:%d , 평균:%d\n", i + 1, sum, avg);
    }

    printf("---과목별 총점 및 평균---\n");

    for (int i = 0; i < NUM_SUBJECT; i++) {
        sum = 0;
        avg = 0;
        for (int j = 0; j < MAX_STU_NUM; j++) {
            sum += score_table[j][i];
            avg = sum / MAX_STU_NUM;
        }
        printf("국어과목- 총점:%d , 평균:%d\n", sum, avg);
    }

    return 0;
}