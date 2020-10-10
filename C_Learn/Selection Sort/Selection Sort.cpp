#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int arr[7] = { 1, 5, 2, 3, 6, 4, 7};
    int save = 0;
        
    printf("정렬 전\n");

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 7; i++) {
        int min = i;
        for (int j = 0; j < 7; j++) {
            if (arr[min] < arr[j]) {
                save = arr[min];
                arr[min] = arr[j];
                arr[j] = save;
            }
        }
    }

    printf("정렬 후\n");

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    return 0;
}