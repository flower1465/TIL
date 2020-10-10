﻿#include <stdio.h>

float bmi_cal(float w, float t);
void bmi_print(float w, float t, float bmi);

int main()
{
	float w, t, bmi;

	printf("input your height: ");
	scanf("%f", &t);

	printf("input your weight: ");
	scanf("%f", &w);

	bmi = bmi_cal(w, t);

	bmi_print(w, t, bmi);

	return 0;
}

float bmi_cal(float w, float t)
{
	return w / ((0.01 * t) * (0.01 * t));
}

void bmi_print(float w, float t, float bmi)
{
	printf("Your Height: %.2f\n", t);
	printf("Your weight: %.2f\n", w);
	printf("Your BMI: %.1f --> ", bmi);
	if (bmi < 18.5)
		printf("low weight!!\n");
	else if (bmi < 23)
		printf("normal!!\n");
	else if (bmi < 25.00)
		printf("overweight!!\n");
	else
		printf("obesity!!\n");
	return 0;
}