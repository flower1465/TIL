#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int arr[5];
    int n = 0;
    int sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < 5; i++) {
        arr[i] = n * (i + 1);
    }

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("%d", sum);


    return 0;
}