﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[2][3];
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}