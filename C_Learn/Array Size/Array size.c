#include <stdio.h>

int main()
{
    int x[5] = { 1,2,3,4,5 };

    printf("배열 이름 x의 값 : %u, %p \n", x, x);
    printf("배열 전체 메모리 크기 sizeof(x) \t\t : %d\n", sizeof(x));
    printf("배열 원소 하나의 메모리 크기 sizeof(x[0])\t : %d\n", sizeof(x[0]));
    printf("배열의 크기 \t\t\t\t\t : %d\n", sizeof(x) / sizeof(x[10]));

    return 0;
}
