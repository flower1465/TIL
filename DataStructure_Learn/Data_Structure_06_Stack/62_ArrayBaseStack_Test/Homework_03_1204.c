#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

#define TRUE 1
#define FALSE 0

int stack[SIZE];
int top = -1;

void Push(data);
char Pop();
int Full();
int Empty();
void Print();

int main()
{   
    char select;
    int data;

    while (1)
    {
        printMenu();
        scanf(" %c", &select);

        switch (select)
        {
        case '1':
            printf("스택에 삽입할 데이타를 입력하시오.\n");
            scanf("%d", &data);
            Push(data);
            break;
        case '2':
            Pop();
            break;
        case '3':
            Print();
            break;
        case 'q':
            return 0;
        }
    }
}

void Push(data) {
    if (!Full()) { // 스택이 overfow가 아닌 경우
        top++; // top를 1 증가
        stack[top] = data;
        printf("\n");
        printf("[Stack Data]:");
        for (int i = 0; i <= top; i++) {
            printf(" %d", stack[i]);
        }
    }
}

char Pop() {
    if (!Empty()) { // 배열이 비어있지 않은 경우
        char temp = stack[top];
        printf("[%d] 데이타가 삭제되었습니다.\t[Stack Data]: %d", stack[top], stack[top - 1]);
        top--;
        return temp;
    }
}

int Full() {
    if (top >= SIZE - 1) { //SIZE - 1인 이유는 배열이 0번 index부터 시작하기 때문
        printf("Stack overfow!!");
        return TRUE;
    }
    return FALSE;
}

int Empty() {
    if (top == -1) { //top == -1인 경우 stack가 비었다는 의미
        printf("Stack underfow!!");
        return TRUE;
    }
    return FALSE;
}

void Print() {
    if (!Empty()) {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

printMenu()
{
    printf("\n\n+++++++++++++++++++++++++++++\n");
    printf("\t1 - 삽입 \n");
    printf("\t2 - 삭제 \n");
    printf("\t3 - 출력 \n");
    printf("\tq - 프로그램 종료 \n");
    printf("+++++++++++++++++++++++++++++\n");
    printf("메뉴를 선택하세요. >> \n");
}