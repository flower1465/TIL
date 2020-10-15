#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define _TYPE_OF_FUCTION_

int Fibonacci(int n) {

	int result = 0;
	int f1 = 1, f2 = 0;

	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		for (int i = 2; i <= n; i++) {
			result = f1 + f2;
			f2 = f1;
			f1 = result;
		}
	}

	return result;
}

int FibonacciRecursive(int n) {
	if (n >= 1 && n <= 2) {
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int n;

	printf("피보나치 수열의 n번째 수(양의 정수)를 입력하시오!\n");
	printf("종료시 문자를 입력!\n");

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
#ifdef _TYPE_OF_FUCTION_
			printf("피보나치 수열의 [fibonacci %2d]의 결과 : %d\n", n, Fibonacci(n));
	}
#else
			printf("피보나치 수열의 [fibonacci %2d]의 결과 : %d\n", n, Fibonacci(n));
		}
	}
#endif

	return 0;
}
