#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DBLinkedList.h"


void printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - ���� \n");
	printf("\t2 - ���� \n");
	printf("\t3 - ��� - ������ ������ �̵��ߴ� ���� ������ �̵��Ͽ� �ѹ��� ��ȸ\n");
	printf("\tq - ���α׷� ���� \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("�޴��� �����ϼ���. >> \n");
}

void printList(List* list)
{
	int data;

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(list));

	if (LFirst(list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		// �� ��° ������ ������ ��ȸ
		// ������ - ������ ���� �̵��ϸ� ��ȸ
			while (LNext(list, &data))    
				printf("%d ", data);
		// ������ - ���� ���� �̵��ϸ� ��ȸ
			while (LPrevious(list, &data))    
				printf("%d ", data);
	}
	printf("\n\n");
}


void deleteList(List* list, int target)
{
	int data;

	if (LFirst(list, &data))
	{
		if (data == target) {
			LRemove(list);		// ���� - DBLinkedList_for_Student.c�� �ִ� LRemove �Լ��� �����ϵ���!!
		}
		while (list->cur != NULL) {
			/* ���� ���� 
			LRemove���� cur ��尡 ����ǳ� ������ �ȵǾ������Ƿ� ���ѷ����� �� �� �ִ�.  
			�׷��Ƿ� LRemove ������ �ϼ��� �� ��  �Ʒ� ���� �߰��Ͽ� Debugging�ϵ��� �Ѵ�. 
			*/
#if 1 
			if (list->cur->data == target)
				LRemove(list);
			else
#endif
				list->cur = list->cur->next; 
		}
	}
}

void freeList(List* list)
{
	Data data;
	Node* freeNode = list->head;
	Node* freeNodeNext = freeNode;

	while (freeNodeNext != NULL) {
		freeNodeNext = freeNode->next;
		data = freeNode->data;
		free(freeNode);
		freeNode = freeNodeNext;

		(list->numOfData)--;
		printf("[%d]free-", data);

	}
}


int main(void)
{
	List list;
	int data;
	ListInit(&list);
	//����Ʈ�� ����Ÿ ���Խ� WhoIsPrecede�� �ݹ��Լ� �������� ���ĵ� ����Ÿ�� �����ϰ��� �Ѵ�. 
	char menu = '1';	// Default 

	while (1) {
		printMenu();
		scanf(" %c", &menu);

		switch (menu)
		{
		case '1':		// ����
			printf("����Ʈ�� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf(" %d", &data);
			LInsert(&list, data);
			break;
		case '2':
			printf("����Ʈ���� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf(" %d", &data);
			deleteList(&list, data);
			break;
		case '3':
			printList(&list);
			break;

		case 'q':		// ����
			freeList(&list);
			return -1;

		default:		// ����ó��
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}

	}
	return 0;
}