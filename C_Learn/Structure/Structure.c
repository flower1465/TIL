//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//struct _student {
//	int nGrade;
//	int nClass;
//	int nNumber;
//	char szName[20];
//	char szTel[15];
//	char szMajor[20];
//	int temp;
//
//} student;
//
//int main()
//{
//	printf("nGrade : %d\n", offsetof(struct _student. nGrade));
//	printf("nClass : %d\n", offsetof(struct _student. nClass));
//	printf("nNumber : %d\n", offsetof(struct _student. nNumber));
//	printf("szName : %d\n", offsetof(struct _student. szName));
//	printf("szTel : %d\n", offsetof(struct _student. szTel));
//	printf("szMajor : %d\n", offsetof(struct _student. szMajor));
//	printf("temp : %d\n", offsetof(struct _student. temp));
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//#pragma pack(push, 1)
//struct _student {
//	int nGrade;
//	int nClass;
//	int nNumber;
//	char szName[20];
//	char szTel[15];
//	char szMajor[20];
//
//} st;
//#pragma pack(pop)
//
//int main()
//{
//	printf("struct student 크기 : %d\n", sizeof(struct _student));
//	printf("변수 st의 크기 : %d\n", sizeof(st));
//}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct person {
    int no;
    char name[11];
    int age;
};

int main()
{   
    struct person p1, p2;
    struct person p3 = { 4, "박승준", 17 };

    printf("번호 : %d 이름 : %s 나이 : %d\n",
        p3.no, p3.name, p3.age);

    p1 = p3;

    printf("번호 : %d 이름 : %s 나이 : %d\n",
        p1.no, p1.name, p1.age);
    return 0;
}


//문자열
//p2 name = "서건희"; 문자열은 이케 하면 안됨
//strcpy(p2 name, "서건희"); 이케 해야함