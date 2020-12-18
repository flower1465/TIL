#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

int isFull() {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return 0;
}

void Push(int data) {
    if (!isFull()) {
        top++;
        stack[top] = data;
    }
}

int Pop() {
    if (!isEmpty()) {
        int temp = stack[top];
        top--;
        return temp;
    }
}

int Peek() {
    if (!isEmpty()) {
        return stack[top];
    }
}

void Print() {
    if (!isEmpty()) {
        for (int i = 0; i <= top; i++) {
            printf(" %d ", stack[i]);   
        }
        printf("\n");
    }
}

int main()
{   
    Pop();
    Push(12);
    Push(8);
    Push(519);
    Push(519);
    Push(95);
    Push(14);
    Push(2);
    Pop();
    Peek();
    Print();
    Push(79);
    Push(16);
    Pop();
    Pop();
    Pop();
    Print();

    return 0;
}


int isFull() {
    if (top >= SIZE - 1) {
        printf("stack overflow");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (top == -1) {
        printf("stack underflow");
        return 1;
    }
    return 0;
}