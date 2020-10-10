#include <stdio.h>
#include "student.h"


int main()
{
	struct _student s1 = { 1, 2, 4, "박승준", "010-0000-0000", "컴퓨터" };

	printf("학년\t: %d \n", s1.nGrade);
	printf("반\t: %d \n", s1.nClass);
	printf("번호\t: %d \n", s1.nNumber);
	printf("이름\t: %s \n", s1.szName);
	printf("전화번호\t: %s \n", s1.szTel);
	printf("전공\t: %s \n", s1.szMajor);

}