﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func1(int a, float r, int n)
{
	float S;
	r /= 100;
	S = (a + ((a * r) * n));
	printf("단리로 계산할시 원리금액 합계 : %.0f\n", S);
	return;
}

void func2(float a, float r, int n)
{
	r /= 100;
	for (int i = 0; i < n; i++)
	{
		a = a + a * r;
	}
	printf("복리로 계산할시 원리금액 합계 : %.0f\n", a);
	return;
}

int main()
{
	int won, year, S;
	float r;

	printf("납입액을 입력하세요. ");
	scanf("%d", &won);

	printf("이율을 입력하세요. ");
	scanf("%f", &r);

	printf("기간을 입력하세요. ");
	scanf("%d", &year);

	printf("월 납입액 \t : %d\n", won);
	printf("이율\t\t : %.02f%%\n", r);
	printf("기간\t\t : %d\n", year);

	func1(won, r, year);
	func2(won, r, year);

	return 0;
}