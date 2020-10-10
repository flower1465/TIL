#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 5
#include <stdio.h>


int main()
{
    int i;
    int int_array[MAX_NUM];
    

    for (i = 0; i < MAX_NUM; i++) {
        scanf("%d", &int_array[i]);
    }

    printf("-----순차출력-----\n");

    for (i = 0; i < MAX_NUM; i++) {
        printf("[%d]번째 배열의 값 : %d\n", i+1, int_array[i]);
    }

    printf("-----역순 출력-----\n");

    for (i = MAX_NUM; i > 0; i--) {
        printf("[%d]번째 배열의 값 : %d\n", i, int_array[i-1]);
    }
    return 0;
}


/*#include <stdio.h>

int main()
{
    int i;
    int int_array[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    for (i = 0; i < 10; i++) {
        printf("[%d]번째 배열의 값 : %d\n", i + 1, int_array[i]);

    }
    return 0;
}*/