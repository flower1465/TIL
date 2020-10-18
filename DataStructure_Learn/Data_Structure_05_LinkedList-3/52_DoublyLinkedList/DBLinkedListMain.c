#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DBLinkedList.h"


void printMenu()
{
	printf("\n\n+++++++++++++++++++++++++++++\n");
	printf("\t1 - 삽입 \n");
	printf("\t2 - 삭제 \n");
	printf("\t3 - 출력 - 오른쪽 끝으로 이동했다 왼쪽 끝으로 이동하여 한바퀴 순회\n");
	printf("\tq - 프로그램 종료 \n");
	printf("+++++++++++++++++++++++++++++\n");
	printf("메뉴를 선택하세요. >> \n");
}

void printList(List* list)
{
	int data;

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(list));

	if (LFirst(list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		// 두 번째 이후의 데이터 조회
		// 정방향 - 오른쪽 노드로 이동하며 조회
			while (LNext(list, &data))    
				printf("%d ", data);
		// 역방향 - 왼쪽 노드로 이동하며 조회
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
			LRemove(list);		// 숙제 - DBLinkedList_for_Student.c에 있는 LRemove 함수를 구현하도록!!
		}
		while (list->cur != NULL) {
			/* 주의 사항 
			LRemove에서 cur 노드가 변경되나 구현이 안되어있으므로 무한루프가 돌 수 있다.  
			그러므로 LRemove 구현이 완성을 한 후  아래 문장 추가하여 Debugging하도록 한다. 
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
	//리스트에 데이타 삽입시 WhoIsPrecede의 콜백함수 기준으로 정렬된 데이타를 삽입하고자 한다. 
	char menu = '1';	// Default 

	while (1) {
		printMenu();
		scanf(" %c", &menu);

		switch (menu)
		{
		case '1':		// 삽입
			printf("리스트에 삽입할 데이타를 입력하시오. \n");
			scanf(" %d", &data);
			LInsert(&list, data);
			break;
		case '2':
			printf("리스트에서 삭제할 데이타를 입력하시오. \n");
			scanf(" %d", &data);
			deleteList(&list, data);
			break;
		case '3':
			printList(&list);
			break;

		case 'q':		// 종료
			freeList(&list);
			return -1;

		default:		// 예외처리
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}

	}
	return 0;
}