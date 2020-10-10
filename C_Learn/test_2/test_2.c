#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	char x;
	scanf("%d %c %d", &a, &x, &b);
	switch (x) {
	case '+':
		printf("%d %c %d = %d", a, x, b, a + b);
		break;
	case '-':
		printf("%d %c %d = %d", a, x, b, a - b);
		break;
	case '*':
		printf("%d %c %d = %d", a, x, b, a * b);
		break;
	case '/':
		printf("%d %c %d = %d", a, x, b, a / b);
	}
	return 0;
}