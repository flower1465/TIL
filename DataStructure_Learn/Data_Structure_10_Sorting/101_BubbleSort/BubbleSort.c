#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < (n - i); j++) {
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main(void)
{
	//int arr[4] = {3, 2, 4, 1};
	int arr[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	//int arr[10] = { 82, 34, 58, 3, 6, 21, 88, 10, 49, 17 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++) {
		printf("%d", arr[i]);
	}

	printf("\n");
	return 0;
}