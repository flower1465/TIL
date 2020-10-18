#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "CLinkedList.h"

void printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - 삽입 -머리\n");
	printf("\t2 - 삽입 -꼬리\n");
	printf("\t3 - 삭제 \n");
	printf("\t4 - 출력 \n");
	printf("\tq - 프로그램 종료 \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("메뉴를 선택하세요. >> \n");
}

#if 0  
//기존 printList
void printList(List* list)
{
	int data;

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(list));

	if (LFirst(list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(list, &data))    // 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}

	printf("\n\n");
}
#endif 

// 위 기존 printList 구현을 참고하여 구현하여라!! 
// 그러나 기존 printList는 LNext가 false가 리턴되는 경우가 없으므로 무한루프가 된다. 해당 부분 고려해보도록 하여라!!
// 단 한줄만 수정하면 됨!! 
void printList(List* list)
{
	int data;

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(list));

	if (LFirst(list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (list->cur != list->tail) {  // 두 번째 이후의 데이터 조회
			LNext(list, &data);
			printf("%d ", data);
		}
			
	}

	printf("\n\n");
}

#if 0
//기존 deleteList
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

// 위 기존 deleteList 구현을 참고하여 구현하여라!! 
// 그러나 기존 deleteList에서 LNext가 false가 리턴되는 경우가 없으므로 무한루프가 된다. 해당 부분 고려해보도록 하여라!!
// 단 한줄만 수정하면 됨!! 
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
//기존 freeList
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

// 위 기존 freeList 구현을 참고하여 구현하여라!! 
// 그러나 기존 freeList 의 경우 원형이므로 freeNodeNext가 NULL을 반환하는 경우가 없으므로 무한루프가 된다. 해당 부분 고려해보도록 하여라!!
// 단 한줄만 수정하면 됨!! 
void freeList(List* list)
{

}



int main(void)
{

	/*** List의 생성 및 초기화 ***/
	List list;
	int data;
	ListInit(&list);
	char menu = '1';	// Default 

	while (1) {
		printMenu();
		scanf(" %c", &menu);

		switch (menu)
		{
		case '1':		// 머리에 삽입
			printf("리스트에 머리에 삽입할 데이타를 입력하시오. \n");
			scanf(" %d", &data);
			LInsertFront(&list, data);
			break;
		case '2':		// 꼬리에 삽입
			printf("리스트에 꼬리에 삽입할 데이타를 입력하시오. \n");
			scanf(" %d", &data);
			LInsert(&list, data);
			break;
		case '3':
			printf("리스트에서 삭제할 데이타를 입력하시오. \n");
			scanf(" %d", &data);
			// 입력받은 data를 리스트에서 삭제하는 함수(deleteList)를 기존 코드를 참고하여 구현하여라!
			deleteList(&list, data);
			break;
		case '4':
			// 리스트내에 있는 모든 원소를 출력하는 함수(printList)를 기존 코드를 참고하여 구현하여라!
			printList(&list);			
			break;

		case 'q':		// 종료
			// 리스트에 있는 모든 원소의 메모리를 해제시키는 함수(freeList)를 기존 코드를 참고하여 구현하여라!
			freeList(&list);
			return -1;

		default:		// 예외처리
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}

	}
	return 0;
}