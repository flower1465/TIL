#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_STU_NUM 5
#define NUM_SUBJECT 3

char* SUB[NUM_SUBJECT] = { "국어", "수학", "영어" };

void print_score(int* s_table)
{
	int i, j;
	int total_stu[MAX_STU_NUM];
	int total_sub[NUM_SUBJECT];
	memset(total_sub, 0x00, sizeof(int) * NUM_SUBJECT);
	memset(total_stu, 0x00, sizeof(int) * MAX_STU_NUM);

	for (i = 0; i < MAX_STU_NUM; i++)
	{
		for (j = 0; j < NUM_SUBJECT; j++)
		{
			total_stu[i] += *(s_table + i * NUM_SUBJECT + j);
			total_sub[j] += *(s_table + i * NUM_SUBJECT + j);
		}
	}

	putchar('\t');
	for (i = 0; i < NUM_SUBJECT; i++)
		printf("%s ", SUB[i]);
	puts("\t\t총점  평균");

	for (i = 0; i < MAX_STU_NUM; i++)
	{
		printf("%d번\t", i + 1);

		for (j = 0; j < NUM_SUBJECT; j++)
			printf("%d   ", *(s_table + i * NUM_SUBJECT + j));

		putchar('|');
		printf("\t%d\t%d\n", total_stu[i], total_stu[i] / NUM_SUBJECT);
	}
	puts("-------------------------------------------");

	printf("총점  ");
	for (j = 0; j < NUM_SUBJECT; j++)
		printf("%5d", total_sub[j]);
	puts("  |");

	printf("평균  ");
	for (j = 0; j < NUM_SUBJECT; j++)
		printf("%5d", total_sub[j] / MAX_STU_NUM);
	puts("  |");
}

int main()
{
	int score_table[MAX_STU_NUM][NUM_SUBJECT] = {
		{80,60,90},
		{95,77,80},
		{40,30,55},
		{10,14,20},
		{42, 30,66},
	};

	print_score(score_table);

	return 0;
}