#include <stdio.h>
#define CUR_YEAR 2020

int calc_age(int year)
{
    int age;
    int result;

    age = (CUR_YEAR - year) + 1;
    result = age;
    
    return result;
}

int main()
{
    int year, age;
    int result;
    scanf_s("%d", &year);
    result = calc_age(year);

    printf("현재 나이는 %d살입니다.", result);
    return 0;
}