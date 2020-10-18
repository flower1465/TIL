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

		// case 1 : current 노드 앞, 뒤에 아무노드도 연결 되지 않은 경우
	if (plist->cur->prev == NULL && plist->cur->next == NULL) {
		plist->head = NULL;
		plist->cur = NULL;
	}
		// case 2 : current 노드 앞에는 연결된 노드가 없으나, 뒤에는 있는 경우 
	else if (plist->cur->prev == NULL && plist->cur->next != NULL) {

	}
		// case 3 : current 노드 앞에는 연결된 노드가 있으나, 뒤에는 없는 경우 

		// current 노두 앞, 뒤 모두 연결 된 경우
		// case 4 : cur 노드 양쪽에 모두 노드가 있는 경우
		

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}



//// case 1 : current 노드 앞, 뒤에 아무노드도 연결 되지 않은 경우
//if (plist->cur->prev == NULL && plist->cur->next == NULL) { // 노드가 1개인경우
//	plist->head = NULL;
//	plist->cur = plist->head;
//	printf("case1 ");
//}	// case 2 : current 노드 앞에는 연결된 노드가 없으나, 뒤에는 있는 경우 
//else if (plist->cur->prev == NULL && plist->cur->next != NULL) {
//	plist->cur->next->prev = plist->cur->prev;  // NULL 삽입
//	plist->head = plist->cur->next; //head가 사라지므로 옮겨주어야 한다. 
//	plist->cur = plist->cur->next; // or plist->cur = plist->head; 도 가능
//	printf("case2 ");
//}  // case 3 : current 노드 앞에는 연결된 노드가 있으나, 뒤에는 없는 경우 
//else if (plist->cur->prev != NULL && plist->cur->next == NULL) {
//	plist->cur->prev->next = plist->cur->next; // NULL 삽입 
//	plist->cur = plist->cur->prev;
//	printf("case3 ");
//} // current 노두 앞, 뒤 모두 연결 된 경우
//else { // case 4 : cur 노드 양쪽에 모두 노드가 있는 경우
//	plist->cur->prev->next = plist->cur->next;
//	plist->cur->next->prev = plist->cur->prev;
//	plist->cur = plist->cur->prev;
//	printf("case4 ");
//}