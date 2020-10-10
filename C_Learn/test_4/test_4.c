#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int n;

    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
                printf("%d", i + 1);
        }
        printf("\n");
    }
    return 0;
}