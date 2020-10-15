#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _TYPE_OF_FUCTION_

float get_compound_interest(float amount, float rate, int year, float eyoul) {
    float result = 0;

    for (int i = 1; i <= year; i++) {
        eyoul *= (rate + 1);
    }

    result = amount * eyoul;

    return result;
}

float get_compound_interest_Recursive(float amout, float rate, int year, float eyoul) {
    if (year == 0) {
        return amout * eyoul;
    }
    else {
        return get_compound_interest_Recursive(amout, rate, year - 1, eyoul *= (rate + 1));
    }
}

int main()
{
    float amount, rate;
    float sum_of_compound = 0.0f;
    int nYear;

    printf("납입액, 이율, 기간을 차례대로 입력하세요. \n");
    printf("종료시 문자를 입력!\n");

    //납입액, 이율체크가 제대로 안되어있음. 

    while (scanf("%f %f %d", &amount, &rate, &nYear) == 3) {
        printf("\n\n월 납입액\t: %.f\n", amount);
        printf("이율 \t\t: %.2f%%\n", rate);
        printf("기간 \t\t: %d\n", nYear);
        if (nYear < 0) printf("기간 설정이 잘못되었습니다.!!!\n");
        else
#ifdef _TYPE_OF_FUCTION_
            sum_of_compound = get_compound_interest(amount, rate * 0.01f, nYear, 1);
#else
            sum_of_compound = get_compound_interest_Recursive(amount, rate * 0.01f, nYear, 1);
#endif
        printf("복리로 계산시 원리금 합계 : %.f\n\n", sum_of_compound);
    }

    return 0;
}