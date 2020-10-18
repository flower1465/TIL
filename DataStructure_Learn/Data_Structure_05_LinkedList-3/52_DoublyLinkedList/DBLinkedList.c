#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if(plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == NULL )
		return FALSE;
	
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL )
		return FALSE;

	plist->cur = plist->cur->prev;

	*pdata = plist->cur->data;

	return TRUE;
}


Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

		// case 1 : current ��� ��, �ڿ� �ƹ���嵵 ���� ���� ���� ���
	if (plist->cur->prev == NULL && plist->cur->next == NULL) {
		plist->head = NULL;
		plist->cur = NULL;
	}
		// case 2 : current ��� �տ��� ����� ��尡 ������, �ڿ��� �ִ� ��� 
	else if (plist->cur->prev == NULL && plist->cur->next != NULL) {

	}
		// case 3 : current ��� �տ��� ����� ��尡 ������, �ڿ��� ���� ��� 

		// current ��� ��, �� ��� ���� �� ���
		// case 4 : cur ��� ���ʿ� ��� ��尡 �ִ� ���
		

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}



//// case 1 : current ��� ��, �ڿ� �ƹ���嵵 ���� ���� ���� ���
//if (plist->cur->prev == NULL && plist->cur->next == NULL) { // ��尡 1���ΰ��
//	plist->head = NULL;
//	plist->cur = plist->head;
//	printf("case1 ");
//}	// case 2 : current ��� �տ��� ����� ��尡 ������, �ڿ��� �ִ� ��� 
//else if (plist->cur->prev == NULL && plist->cur->next != NULL) {
//	plist->cur->next->prev = plist->cur->prev;  // NULL ����
//	plist->head = plist->cur->next; //head�� ������Ƿ� �Ű��־�� �Ѵ�. 
//	plist->cur = plist->cur->next; // or plist->cur = plist->head; �� ����
//	printf("case2 ");
//}  // case 3 : current ��� �տ��� ����� ��尡 ������, �ڿ��� ���� ��� 
//else if (plist->cur->prev != NULL && plist->cur->next == NULL) {
//	plist->cur->prev->next = plist->cur->next; // NULL ���� 
//	plist->cur = plist->cur->prev;
//	printf("case3 ");
//} // current ��� ��, �� ��� ���� �� ���
//else { // case 4 : cur ��� ���ʿ� ��� ��尡 �ִ� ���
//	plist->cur->prev->next = plist->cur->next;
//	plist->cur->next->prev = plist->cur->prev;
//	plist->cur = plist->cur->prev;
//	printf("case4 ");
//}