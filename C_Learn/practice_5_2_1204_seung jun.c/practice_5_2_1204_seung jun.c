﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get()
{
	const max = 585;
	int minute, fee, day = 0;
	char ch[50];

	printf("주차시간(분)을 입력하세요 : ");
	gets(ch);

	if (!(strcmp(ch, "q")))
		return 1;

	else
	{
		minute = atoi(ch);

		if (minute > 1440)
		{
			day = minute / 1440;
			minute %= 1440;
		}

		if (minute <= 30)
			printf("주차요금은  %d원  입니다.\n", 24000 * day + 1200);

		else if (minute > max)
			printf("주차요금은  %d원  입니다.\n", 24000 * day + 24000);

		else
		{
			fee = minute / 15;
			if (minute % 15 != 0)
				fee++;
			printf("주차요금은  %d원  입니다.\n", 24000 * day + fee * 600);
		}
	}

	return 0;
}

int main()
{
	printf("프로그램을 종료하려면 q를, 계속하려면 그 외의 값을 입력하세요\n\n");

	while (1)
	{

		if (get())
			break;

	}


	return 0;
}