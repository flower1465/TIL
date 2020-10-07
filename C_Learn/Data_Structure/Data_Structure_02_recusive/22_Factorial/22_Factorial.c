#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define _TYPE_OF_FUCTION_

int Factorial(int n) {
	int sum = 1;

	for (int i = 2; i <= n; i++) {
		sum *= i;
	}
	return sum;
}

int FactorialRecursive(int n) {
	if (n == 1) {
		return 1;
	}
	return FactorialRecursive(n - 1) * n;
}

int main()
{
	int n;

	printf("n!을 계산할 수 있는 n의 값(즉, 양의 정수)를 입력하시오.\n");
	printf("종료시 문자를 입력!\n");

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
#ifdef _TYPE_OF_FUCTION_
			printf("n!의 결과 : %d\n", Factorial(n));
		}
#else
			printf("n!의 결과 : %d\n", FactorialRecursive(n));
		}
#endif

	return 0;
}