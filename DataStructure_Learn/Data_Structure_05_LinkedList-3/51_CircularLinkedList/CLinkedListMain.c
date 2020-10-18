#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "CLinkedList.h"

void printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - ���� -�Ӹ�\n");
	printf("\t2 - ���� -����\n");
	printf("\t3 - ���� \n");
	printf("\t4 - ��� \n");
	printf("\tq - ���α׷� ���� \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("�޴��� �����ϼ���. >> \n");
}

#if 0  
//���� printList
void printList(List* list)
{
	int data;

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(list));

	if (LFirst(list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}

	printf("\n\n");
}
#endif 

// �� ���� printList ������ �����Ͽ� �����Ͽ���!! 
// �׷��� ���� printList�� LNext�� false�� ���ϵǴ� ��찡 �����Ƿ� ���ѷ����� �ȴ�. �ش� �κ� ����غ����� �Ͽ���!!
// �� ���ٸ� �����ϸ� ��!! 
void printList(List* list)
{
	int data;

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(list));

	if (LFirst(list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (list->cur != list->tail) {  // �� ��° ������ ������ ��ȸ
			LNext(list, &data);
			printf("%d ", data);
		}
			
	}

	printf("\n\n");
}

#if 0
//���� deleteList
void deleteList(List* list, int target)
{
	int data;

	if (LFirst(list, &data))
	{
		if (data == target)
			LRemove(list);

		while (LNext(list, &data))
		{
			if (data == target)
				LRemove(list);
		}
	}
}
#endif 

// �� ���� deleteList ������ �����Ͽ� �����Ͽ���!! 
// �׷��� ���� deleteList���� LNext�� false�� ���ϵǴ� ��찡 �����Ƿ� ���ѷ����� �ȴ�. �ش� �κ� ����غ����� �Ͽ���!!
// �� ���ٸ� �����ϸ� ��!! 
void deleteList(List* list, int target)
{
	int data;

	if (LFirst(list, &data))
	{
		if (data == target)
			LRemove(list);

		while (list->cur != list->tail)
		{
			LNext(list, &data);

			if (data == target)
				LRemove(list);
		}
	}
}

#if 0 
//���� freeList
void freeList(List* list)
{
	Data data;
	Node* freeNode = list->tail;
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
#endif 

// �� ���� freeList ������ �����Ͽ� �����Ͽ���!! 
// �׷��� ���� freeList �� ��� �����̹Ƿ� freeNodeNext�� NULL�� ��ȯ�ϴ� ��찡 �����Ƿ� ���ѷ����� �ȴ�. �ش� �κ� ����غ����� �Ͽ���!!
// �� ���ٸ� �����ϸ� ��!! 
void freeList(List* list)
{

}



int main(void)
{

	/*** List�� ���� �� �ʱ�ȭ ***/
	List list;
	int data;
	ListInit(&list);
	char menu = '1';	// Default 

	while (1) {
		printMenu();
		scanf(" %c", &menu);

		switch (menu)
		{
		case '1':		// �Ӹ��� ����
			printf("����Ʈ�� �Ӹ��� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf(" %d", &data);
			LInsertFront(&list, data);
			break;
		case '2':		// ������ ����
			printf("����Ʈ�� ������ ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf(" %d", &data);
			LInsert(&list, data);
			break;
		case '3':
			printf("����Ʈ���� ������ ����Ÿ�� �Է��Ͻÿ�. \n");
			scanf(" %d", &data);
			// �Է¹��� data�� ����Ʈ���� �����ϴ� �Լ�(deleteList)�� ���� �ڵ带 �����Ͽ� �����Ͽ���!
			deleteList(&list, data);
			break;
		case '4':
			// ����Ʈ���� �ִ� ��� ���Ҹ� ����ϴ� �Լ�(printList)�� ���� �ڵ带 �����Ͽ� �����Ͽ���!
			printList(&list);			
			break;

		case 'q':		// ����
			// ����Ʈ�� �ִ� ��� ������ �޸𸮸� ������Ű�� �Լ�(freeList)�� ���� �ڵ带 �����Ͽ� �����Ͽ���!
			freeList(&list);
			return -1;

		default:		// ����ó��
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}

	}
	return 0;
}