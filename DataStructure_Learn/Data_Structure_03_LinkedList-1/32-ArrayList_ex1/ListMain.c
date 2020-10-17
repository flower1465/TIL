#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DLinkedList.h"

printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - ���� \n");
	printf("\t2 - ���� \n");
	printf("\t3 - ��� \n");
	printf("\tq - ���α׷� ���� \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("�޴��� �����ϼ���. >> \n");
}

void printList(List* list)
{
	//p81 �� �����Ͽ� ����Ʈ���� �����͸� ������ִ� �Լ��� �ۼ��϶�. 
	int data;

	printf("���� �������� �� : %d \n", LCount(list));

	if (LFirst(list, &data)) {
		printf("%d", data);

		while (LNext(list, &data)) {
			printf("%d", data);
		}
	}
	printf("\n\n");

}

void deleteList(List* list, int target)
{
	//p81 �� �����Ͽ� ���޹��� target �� ����Ʈ������ ��� �������ִ� �Լ��� �ۼ��϶�. 
	int data;

	if (LFirst(list, &data) == target) {
		LRemove(list);

		while (LNext(list, &data)) {
			if (data == target)
				LRemove(list);
		}
	}
}

int main(void)
{

	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data;
	ListInit(&list);
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
			// ����Ʈ���� �ִ� ��� ���Ҹ� ����ϴ� �Լ�(printList)�� �����ϰ� ȣ�� - p.81 ����
			break;

		case 'q':		// ����
			return -1;

		default:		// ����ó��
			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}

	}
	return 0;
}