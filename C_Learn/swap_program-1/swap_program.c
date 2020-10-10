/*#include <stdio.h>

int main()
{
	int n1 = 10, n2 = 20;
	int temp;

	printf("교환 전 - n1:%d, n2:%d\n", n1, n2);
	temp = n1;
	n1 = n2;
	n2 = temp;
	printf("교환 후 - n1:%d, n2:%d\n", n1, n2);

	return 0;
}*/

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
	int n1 = 10, n2 = 20;
	int temp;

	printf("교환 전 - n1:%d, n2:%d\n", n1, n2);
	swap(&n1, &n2);
	printf("교환 후 - n1:%d, n2:%d\n", n1, n2);

	return 0;
}
