#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ConvertBinary(int n) {

	if (n < 2) {
		printf("%d", n);
	}
	else {
		ConvertBinary(n / 2);
		printf("%d", n % 2);
	}

}

int main()
{
	int n;

	printf("2진수를 변환할 10진수를 입력하시오. 단 양의정수\n");
	printf("종료시 문자를 입력!\n");

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
			printf("[10진수] %4d -> [2진수] ", n);
			ConvertBinary(n);
			printf("\n");
		}
	}

	return 0;
}
