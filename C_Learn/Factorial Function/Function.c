#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n)
{
    int i;
    int result = 1;
    if (n == 1)
        return 1;   //1을 반환하고 재귀호출을 끝낸다.
    else {
        for (i = 1; i <= n; i++) {
            result *= i;
        }
    }
    return result;
}


int main()
{
    int n;
    printf("n!을 계산할 수 있는 n의 값(즉, 양의 정수)를 입력하시오!\n");
    scanf("%d", &n);
    if (n < 1) {
        printf("양의 정수를 입력하셔야 합니다!!!");
    }
    else {
        printf("n!의 결과 : %d\n", factorial(n));
    }
    return 0;
}
