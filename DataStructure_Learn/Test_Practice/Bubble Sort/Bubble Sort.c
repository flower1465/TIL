#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 5

void bubble(int arr[], int max) {
    int temp;
    for (int i = max - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{   
    int arr[MAX_SIZE] = { 5, 2, 1, 3, 4, };

    bubble(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
