/*
색       값   곱
black    0    1
brown    1    10
red      2    100
orange   3    1000
yellow   4    10000
green    5    100000
blue     6    1000000
violet   7    10000000
grey     8    100000000
white    9    1000000000
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mlt(char *s1)
{
    int result = 0;

    if (strcmp(s1, "black") == 0)
        result = 0;
    else if (strcmp(s1, "brown") == 0)
        result = 1 *10;
    else if (strcmp(s1, "red") == 0)
        result = 2 * 10;
    else if (strcmp(s1, "orange") == 0)
        result = 3 * 10;
    else if (strcmp(s1, "yellow") == 0)
        result = 4 * 10;
    else if (strcmp(s1, "green") == 0)
        result = 5 * 10;
    else if (strcmp(s1, "blue") == 0)
        result = 6 * 10;
    else if (strcmp(s1, "violet") == 0)
        result = 7 * 10;
    else if (strcmp(s1, "grey") == 0)
        result = 8 * 10;    
    else if (strcmp(s1, "white") == 0)
        result = 9 * 10;

     return result;
}

int MLT(char *s2)
{
    int result = 0;

    if (strcmp(s2, "black") == 0)
        result = 0;
    else if (strcmp(s2, "brown") == 0)
        result = 1;
    else if (strcmp(s2, "red") == 0)
        result = 2;
    else if (strcmp(s2, "orange") == 0)
        result = 3;
    else if (strcmp(s2, "yellow") == 0)
        result = 4;
    else if (strcmp(s2, "green") == 0)
        result = 5;
    else if (strcmp(s2, "blue") == 0)
        result = 6;
    else if (strcmp(s2, "violet") == 0)
        result = 7;
    else if (strcmp(s2, "grey") == 0)
        result = 8;
    else if (strcmp(s2, "white") == 0)
        result = 9;

    return result;
}

long long int MLT2(char *s3)
{
    int result = 1;

    if (strcmp(s3, "black" == 0)) {
        result *= 10;
    }
    else if (strcmp(s3, "brown" == 0)) {
        result *= 100;
    }
    else if (strcmp(s3, "red" == 0)) {
        result *= 1000;
    }
    else if (strcmp(s3, "orange" == 0)) {
        result *= 10000;
    }
    else if (strcmp(s3, "yellow" == 0)) {
        result *= 100000;
    }
    else if (strcmp(s3, "green" == 0)) {
        result *= 1000000;
    }
    else if (strcmp(s3, "blue" == 0)) {
        result *= 10000000;
    }
    else if (strcmp(s3, "violet" == 0)) {
        result *= 100000000;
    }
    else if (strcmp(s3, "gray" == 0)) {
        result *= 1000000000;
    }
    else if (strcmp(s3, "white" == 0)) {
        result *= 10000000000;
    }

    return result;
}


int main()
{
    char s1[10];
    char s2[10];
    char s3[10];

    long long int sum = 0;

    scanf("%s %s %s", s1, s2, s3);

    int result = mlt(&s1);
    int result2 = MLT(&s2);
    int result3 = MLT2(&s3);
    sum += result;
    sum += result2;
    sum *= result3;

    printf("%lld", sum);

    return 0;
}