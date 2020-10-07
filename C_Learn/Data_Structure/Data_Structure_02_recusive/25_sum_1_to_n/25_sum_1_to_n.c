#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _TYPE_OF_FUCTION_

int SumOfN(int n) {
	int sum = 0;

	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int SumOfNRecursive(int n) {
	if (n == 0) {
		return 0;
	}

	return n + SumOfNRecursive(n);
}

int main()
{
	int n;

	printf("1부터 n까지의 합을 구할 n(양의 정수)을 입력하시오!\n");
	printf("종료시 문자를 입력!\n");

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
			printf("1부터 %3d까지의 합 : %d\n", n, SumOfN(n));
		}
	}

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
#ifdef _TYPE_OF_FUCTION_
			printf("1부터 %3d까지의 합 : %d\n", n, SumOfN(n));
		}
#else
			printf("1부터 %3d까지의 합 : %d\n", n, SumOfNRecursive(n));
	}
}
#endif

	return 0;
}
