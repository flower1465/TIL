#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "D:/Developement/2020_Data Structure/Data_Structure_04_LinkedList-2/42_DummyLinkedList/DLinkedList.h"


printMenu()
{
    printf("\n\n+++++++++++++++++++++++++++++\n");
    printf("\t1 - ���� \n");
    printf("\t2 - ���� \n");
    printf("\t3 - ��� \n");
    printf("\t4 - �� ������ ����\n");
    printf("\tq - ���α׷� ���� \n");
    printf("+++++++++++++++++++++++++++++\n");
    printf("�޴��� �����ϼ���. >> \n");
}

void printList(List* list)
{
    //p81 �� �����Ͽ� ����Ʈ���� �����͸� ������ִ� �Լ��� �ۼ��϶�.
    int data;
    
    puts("\n");
    
    if (LFirst(list, &data)) {
        printf("%d ", data);
        while (LNext(list, &data)) {
            printf("%d ", data);
        }
    }
    
    printf("\n%d��", LCount(list));
}

void deleteList(List* list, int target)
{
    //p81 �� �����Ͽ� ���޹��� target �� ����Ʈ������ ��� �������ִ� �Լ��� �ۼ��϶�.
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

        printf("�����ϴ� �� : %d \n", delNode->data);
        free(delNode);
    }
}


int main(void)
{

    // ArrayList�� ���� �� �ʱ�ȭ 
    List list;
    int data;
    ListInit(&list);
    char menu = '1';        // Default

    while (1) {
        printMenu();
        scanf(" %c", &menu);

        switch (menu)
        {
        case '1':               // ����
            printf("����Ʈ�� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
            scanf(" %d", &data);
            // �Է¹��� data�� ����Ʈ�� �����ϴ� �Լ��� ȣ�� - p.81 ����
            LInsert(&list, data);
            break;
        case '2':
            printf("����Ʈ���� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
            scanf(" %d", &data);
            // �Է¹��� data�� ����Ʈ���� �����ϴ� �Լ�(deleteList)�� �����ϰ� ȣ�� - p.81 ����
            deleteList(&list, data);
            break;
        case '3':
            // ����Ʈ���� �ִ� ��� ���Ҹ� ����ϴ� �Լ�(printList)�� �����ϰ� ȣ�� - p.81 ����
            printList(&list);
            break;
        case '4':
            freeList(&list);
            break;
        case 'q':
            // ����
            free(list.head);
            return -1;

        default:                // ����ó��
            printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
            break;
        }

    }
    return 0;
}