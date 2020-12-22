#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 5

void select(int arr[], int size) {
    int max, temp;
    for (int i = 0; i < size - 1; i++) {
        max = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (i != max) {
            temp = arr[max]; 
            arr[max] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{   
    int arr[MAX_SIZE] = { 5, 3, 4, 2, 1 };

    select(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
