#include <stdio.h>
#include "student.h"

int main()
{   
    Student* p, s1 = { 1, 1, 21, "이기남", "010-xxxx-xxxx", "컴퓨터" };
    p = &s1;

    printf("s1 -> 구초체 변수 통한 멤버변수 접근\n");
    printf("학년\t: %d \n", s1.nGrade);
    printf("반\t: %d \n", s1.nClass);
    printf("번호\t: %d \n", s1.nNumber);
    printf("이름\t: %s \n", s1.szName);
    printf("전화번호\t: %s \n", s1.szTel);
    printf("전공\t: %s \n", s1.szMajor);

    printf("\n\np -> 구조체 포인터를 통한 멤버변수 접근\n");
    printf("학년\t: %d \n", p-> nGrade);
    printf("반\t: %d \n", p-> nClass);
    printf("번호\t: %d \n", p-> nNumber);
    printf("이름\t: %s \n", p-> szName);
    printf("전화번호\t: %s \n", p-> szTel);
    printf("전공\t: %s \n", p-> szMajor);


    return 0;
}
