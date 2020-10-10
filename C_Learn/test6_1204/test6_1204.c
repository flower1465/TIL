#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int calc(int num1, char op, int num2)
{
	int result;

	switch (op)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
	default:
		result = 0;
	}
	return  result;
}

int main()
{
    int num1, num2, result;
    char op;

    scanf("%d %c %d", &num1, &op, &num2);
    result = calc(num1, op, num2);
    printf("%.d", result);

    return 0;
}
