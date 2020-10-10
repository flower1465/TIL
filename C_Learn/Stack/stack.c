#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 4

int topindex = -1;
int arr[MAX_NUM];

int push(int x)
{
    if (full() == 1) {
        printf("스택이 가득 찼습니다.");
        return 0;
    }
    else {
        topindex++;
        printf("push를 하셨습니다.\n");
        arr[topindex] = x;
    }
}

int pop()
{
    if (empty() == 1) {
        printf("비어있습니다.");
        return 0;
    }
    else {
        printf("pop의 값은 %d입니다.\n", arr[topindex]);
        arr[topindex] = '\0';
        topindex--;
    }
}

void peek()
{
    if (empty == 1) {
        printf("비어있습니다.");
        return 0;
    }
    printf("peek의 값은 %d입니다.\n", arr[topindex]); 
}

int full()
{
    if (topindex >= MAX_NUM) {
        return 1;
    }
    else return 0;
}

int empty()
{
    if (topindex <= -1) {
        return 1;
    }
    else return 0;
}

int main()
{   
    int a, b, c;

    while (1) {
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d", &b);
            push(b);
        }
        else if (a == 1) {
            printf("pop를 하셨습니다.\n");
            pop();
        }
        else if (a == 2) {
            printf("peek를 하셨습니다.\n");
            peek();
        }
    }

    return 0;
}