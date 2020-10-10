#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n)
{
    if (n <= 2) 
        return 1;
    return fibo(n-2) + fibo(n-1);
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", fibo(n));

    return 0;
}