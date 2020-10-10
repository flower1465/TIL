#include <stdio.h>

#define MAX_PER_NUM 10
struct person {
    int no;
    char szName[11];
    int age;
};

typedef struct person Person;

void print_msg(char* szMsg)
{
    printf("----------------------------------------\n");
    printf("%s\n", szMsg);
    printf("----------------------------------------\n");
}

int main()
{
    int i;
    Person array_ps[MAX_PER_NUM] = {
        {11, "이원석", 41},
        {12, "이종은", 42},
        {13, "이주석", 43},
        {14, "임연상", 44},
        {15, "전규현", 45},
        {16, "정지우", 46},
        {17, "조예림", 47},
        {18, "조준서", 48},
        {19, "홍태희", 49},
        {20, "황주영", 50}
    };
    Person* pointer_ps;
    pointer_ps = array_ps;

    print_msg("포인터로 각 원소에 접근");
    for (i = 0; i < MAX_PER_NUM; i++) {
        printf("번호 : %d, 이름 : %s, 나이 : %d\n", pointer_ps[i].no, pointer_ps[i].szName, pointer_ps[i].age);
    }

    print_msg("배열의 각 원소에 접근");
    for (i = 0; i < MAX_PER_NUM; i++) {
        printf("번호 : %d, 이름 : %s, 나이 : %d\n", array_ps[i].no, array_ps[i].szName, array_ps[i].age);
    }

    print_msg("포인터의 가감연산을 활용한 접근");
    for (i = 0; i < MAX_PER_NUM; i++) {
        printf("번호 : %d, 이름 : %s, 나이 : %d\n", (pointer_ps + i)->no, (pointer_ps + i)->szName, (pointer_ps + i)->age);
    }

    print_msg("포인터의 가감연산을 활용한 접근");
    for (pointer_ps = array_ps; pointer_ps != array_ps + MAX_PER_NUM; pointer_ps++) {
        printf("번호 : %d, 이름 : %s, 나이 : %d\n", pointer_ps->no, pointer_ps->szName, pointer_ps->age);
    }

    print_msg("포인터의 가감연산을 활용한 후 간접참조한 후의 접근");
    pointer_ps = array_ps;
    for (i = 0; i < MAX_PER_NUM; i++) {
        printf("번호 : %d, 이름 : %s, 나이 : %d\n", (*(pointer_ps + i)).no, (*(pointer_ps + i)).szName, (*(pointer_ps + i)).age);
    }

    return 0;
}