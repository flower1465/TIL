#include <stdio.h>

int main()
{
	int i, j;
	int array[8][9];

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			array[i - 2][j - 1] = i * j;
		}
	}



	for (int i = 0; i < 8; i++) {
		printf("=====%d단구구단=====\n", i + 2);
		for (int j = 0; j < 9; j++) {
			printf("%d * %d = %2d\n", i + 2, j + 1, array[i][j]);
		}
	}

	return 0;
}