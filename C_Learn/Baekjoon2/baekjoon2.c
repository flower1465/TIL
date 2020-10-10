#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int x , y;
    int n;
    scanf_s("%d %d", &x, &y);

    if (x > 0 && y > 0)
        n = 1;
    else if (x < 0 && y > 0)
        n = 2;
    else if (x < 0 && y < 0)
        n = 3;
    else (x > 0 && y < 0);
        n = 4;

    printf("%d", n);

    return 0;
}
