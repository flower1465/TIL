#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ParkToReal(n)
{
    if (n == 1)
        return 1;
    return n *= ParkToReal(n-1);
}

int main()
{   
    int n;

    scanf("%d", &n);
    printf("%d", ParkToReal(n));

    return 0;
}