#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "D:/Developement/2020_Data Structure/Data_Structure_04_LinkedList-2/42_DummyLinkedList/DLinkedList.h"


printMenu()
{
    printf("\n\n+++++++++++++++++++++++++++++\n");
    printf("\t1 - 삽입 \n");
    printf("\t2 - 삭제 \n");
    printf("\t3 - 출력 \n");
    printf("\t4 - 전 데이터 삭제\n");
    printf("\tq - 프로그램 종료 \n");
    printf("+++++++++++++++++++++++++++++\n");
    printf("메뉴를 선택하세요. >> \n");
}

void printList(List* list)
{
    //p81 을 참고하여 리스트내의 데이터를 출력해주는 함수를 작성하라.
    int data;
    
    puts("\n");
    
    if (LFirst(list, &data)) {
        printf("%d ", data);
        while (LNext(list, &data)) {
            printf("%d ", data);
        }
    }
    
    printf("\n%d개", LCount(list));
}

void deleteList(List* list, int target)
{
    //p81 을 참고하여 전달받은 target 을 리스트내에서 모두 삭제해주는 함수를 작성하라.
    int data;

    if (LFirst(list, &data) && data == target) {
        LRemove(list);
    }
    
    while (LNext(list, &data)) {
        if (data == target) {
            LRemove(list);
        }
    }
}

void freeList(List* list)
{
    
    Node* delNode = list->head;
    Node* delNextNode = list->head->next;

    while (delNextNode != NULL)
    {
        delNode = delNextNode;
        delNextNode = delNextNode->next;

        printf("삭제하는 값 : %d \n", delNode->data);
        free(delNode);
    }
}


int main(void)
{

    // ArrayList의 생성 및 초기화 
    List list;
    int data;
    ListInit(&list);
    char menu = '1';        // Default

    while (1) {
        printMenu();
        scanf(" %c", &menu);

        switch (menu)
        {
        case '1':               // 삽입
            printf("리스트에 삽입할 데이타를 입력하시오. \n");
            scanf(" %d", &data);
            // 입력받은 data를 리스트에 삽입하는 함수를 호출 - p.81 참고
            LInsert(&list, data);
            break;
        case '2':
            printf("리스트에서 삭제할 데이타를 입력하시오. \n");
            scanf(" %d", &data);
            // 입력받은 data를 리스트에서 삭제하는 함수(deleteList)를 구현하고 호출 - p.81 참고
            deleteList(&list, data);
            break;
        case '3':
            // 리스트내에 있는 모든 원소를 출력하는 함수(printList)를 구현하고 호출 - p.81 참고
            printList(&list);
            break;
        case '4':
            freeList(&list);
            break;
        case 'q':
            // 종료
            free(list.head);
            return -1;

        default:                // 예외처리
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
            break;
        }

    }
    return 0;
}