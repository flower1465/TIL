#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_NUM 5

int main()
{
    int i, sum = 0;
    int int_arr[MAX_NUM];

    printf("5개의 정수를 입력해주세요.\n");
    for (i = 0; i < MAX_NUM; i++) {
        scanf("%d", &int_arr[i]);
    }

    for (i = 0; i < MAX_NUM; i++) {
        sum += int_arr[i];
        printf("%d ", int_arr[i]);
    }
    printf(": SUM -> %d", sum);

    return 0;
}
