#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int move(int from, int by, int to, int n) {
	if (n == 1) {
		printf("%d -> %d", from, to);
	}
	else {
		move(from, to, by, n - 1);
		printf("%d -> %d로 이동", from, to);
		move(by, from, to, n-1);
	}
}

int main()
{
	int n;

	printf("하노이탑의 높이를 입력하시오!\n");
	printf("종료시 문자를 입력!\n");

	while (scanf("%d", &n) == 1) {
		if (n < 1) printf("양의 정수를 입력하셔야 합니다!!!\n");
		else {
			move(1, 2, 3, n);
		}
	}
	return 0;
}
