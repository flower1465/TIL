#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int arr[7] = { 2, 4, 3, 1, 5, 7, 6 };
    int save = 0;
    int flag;

    printf("정렬 전");

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 7; i++) {
        flag = 0;
        for (int j = 0; j < 6 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                save = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = save;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    printf("정렬 후");

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");


    return 0;
}