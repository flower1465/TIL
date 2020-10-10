#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "student.h"


void print_1_student(Student stu)
{

}

Student update_1_student(Student stu)
{
    stu.nGrade = 2;
    stu.nClass = 2;
    stu.nNumber = 20;

    strcpy(stu.szName, "홍길동");
    strycy(stu.szTel, "010-1111-1111");
    strcpy(stu.szMajor, "철학과");

    return stu;
}

int main()
{   
    Student s1 = { 1, 2, 4, "박승준", "010-1111-1111", "공통" };
    Student s2;
    s2 = s1;

    return 0;
}


//struct _student {
//	int nGrade;
//	int nClass;
//	int nNumber;
//	char szName[20];
//	char szTel[15];
//	char szMajor[20];
//
//} s1;