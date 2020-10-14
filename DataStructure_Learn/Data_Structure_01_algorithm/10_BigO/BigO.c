#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _SAMPLE_1_

#ifdef _SAMPLE_1_
int funtion_exec(int n)
{
    int i, count = 0;
    for (i = 0; i < n * 100; i++) {
        count++;
    }
    for (i = 0; i < 3; i++) {
        count++;
    }
    return count;
}

#endif

#ifdef _SAMPLE_2_
int funtion_exec(int n)
{
    int i, count = 0;
    for (i = 1; i <= n; i *= 2) {
        count++;
    }
    return count;
}

#endif

#ifdef _SAMPLE_3_
int funtion_exec(int n)
{
    int i, j, count = 0;
    for (i = 0; i < n * 1000; i++) {
        for (j = 0; j < n * 40; j++) {
            count++;
        }
    }
    return count;
}

#endif

#ifdef _SAMPLE_4_
int funtion_exec(int n)
{
    int i, j, count = 0;
    for (i = 0; i < 10000; i++) {
        count++;
    }
    return count;
}

#endif

#ifdef _SAMPLE_5_
int funtion_exec(int n)
{
    int a, b, c, d, count = 0;
    for (a = 0; a < 2 * n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
                for (d = 0; d < 5000; d++) {
                    count++;
                }
            }
        }
    }
    return count;
}

#endif

#ifdef _SAMPLE_6_
int funtion_exec(int n)
{
    int i, count = 0;
    for (i = 0; i < n * 100; i++) {
        count++;
    }
    for (i = 0; i < n; i++) {
        count++;
    }
    return count;
}

#endif

int main()
{
    int n, result_n;

    while (scanf("%d", &n) == 1) {
        result_n = funtion_exec(n);
        printf("%n : 7d 입력에 따른 수행 결과 %d\n", n, result_n);
    }

    return 0;
}