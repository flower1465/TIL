#include "struct.h"

Student s1[MAX_NUM];
int count = 0;

void studentYearDiscrimination(char num[], int* year, int* month, int* day) {       // 학생 주민번호 7번째 자리로 생년월일 판별
    int numDiscrimination[6];
    for (int i = 0; i < 6; i++) {
        numDiscrimination[i] = num[i] - '0';
    }
    *year = numDiscrimination[0] * 10 + numDiscrimination[1];
    *month = numDiscrimination[2] * 10 + numDiscrimination[3];
    *day = numDiscrimination[4] * 10 + numDiscrimination[5];
}

void studentNumDiscrimination(Student num) {                                // 학생 주민번호로 판별
    int year, month, day;
    studentYearDiscrimination(num.szNum, &year, &month, &day);
    switch (num.szNum[6]) {
    case '1':
        year = year + 1900;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 남자, %s\n", num.szMajor);
        break;
    case '2':
        year = year + 1900;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 여자, %s\n", num.szMajor);
        break;
    case '3':
        year = year + 2000;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 남자, %s\n", num.szMajor);
        break;
    case '4':
        year = year + 2000;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 여자, %s\n", num.szMajor);
        break;
    case '5':
        year = year + 1900;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 외국인, 남자, %s\n", num.szMajor);
        break;
    case '6':
        year = year + 1900;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 외국인, 여자, %s\n", num.szMajor);
        break;
    case '7':
        year = year + 2000;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 외국인, 남자, %s\n", num.szMajor);
        break;
    case '8':
        year = year + 2000;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 외국인, 여자, %s\n", num.szMajor);
        break;
    case '9':
        year = year + 1800;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 남자, %s\n", num.szMajor);
        break;
    case '0':
        year = year + 1800;
        printf("%d년 %d월 %d일,", year, month, day);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            printf(" 윤년,");
        else
            printf(" 윤년아님,");
        printf(" 대한민국, 여자, %s\n", num.szMajor);
        break;
    }
}

void userInsert() {
    puts("학생이름을 공백없이 입력하시오!");
    scanf("%s", s1[count].name);
    puts("전공을 공백없이 입력하시오!");
    scanf("%s", s1[count].szMajor);
    puts("주민번호를 공백 및 특수문자없이 13자리의 숫자로 입력하시오!");
    scanf("%s", s1[count].szNum);

    count++;
}

void userPrint() {
    for (int i = 0; i < count; i++) {
        puts("--------------------------------------------------------");
        printf("이름 : %s\n", s1[i].name);
        printf("학과 : %s\n", s1[i].szMajor);
        printf("주민등록번호 : %s\n", s1[i].szNum);
        studentNumDiscrimination(s1[i]);
    }
}

void printUserAll() {
    Student save;
    Student s2[MAX_NUM];
    int year, month, day;
    int year1, month1, day1;
    puts("=============================================================");
    printf("입력받은 %d명의 정보를 생년월일 기준으로 오름차순으로 출력\n\n", count);
    for (int i = 1; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++) {
            studentYearDiscrimination(s1[j].szNum, &year, &month, &day);
            studentYearDiscrimination(s1[j + 1].szNum, &year1, &month1, &day1);
            if (year1 < year) {
                save = s1[j];
                s2[j] = s1[j + 1];
                s2[j + 1] = save;
            }
            else if (year1 == year && month1 < month) {
                save = s1[j];
                s2[j] = s1[j + 1];
                s2[j + 1] = save;
            }
            else if (year1 == year && month1 == month && day1 < day) {
                save = s1[j];
                s2[j] = s1[j + 1];
                s2[j + 1] = save;
            }
            else {
                s2[j] = s1[j];
                s2[j + 1] = s1[j + 1];
            }
        }
    }

    puts("-----------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("%s, ", s2[i].name);
        studentNumDiscrimination(s2[i]);
    }
    puts("\n-----------------------------------------------------");
}

int main(void) {
    char input;

    while (1) {
        puts("\n\n+++++++++++++++++++++++++++++");
        puts("\t1 - 입력");
        puts("\t2 - 출력");
        puts("\t3 - 오름차순 출력");
        puts("\tq - 종료");
        puts("+++++++++++++++++++++++++++++");

        printf("please select!!! >> ");
        scanf(" %c", &input);

        switch (input) {
        case '1':
            userInsert();
            break;
        case '2':
            userPrint();
            break;
        case '3':
            printUserAll();
            break;
        case 'q':
            return 0;
        }
        system("cls");
    }
    return 0;
}