#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct _node {
	char N;
	int K, E, M, C, S, R;
	struct _node* Next;
} Node;

typedef Node* Ldata;

typedef struct _list {
	Ldata Head;
	Ldata Cur;
	Ldata Before;
	int NumOfData;
	int (*comp)(Ldata, Ldata);
} LinkedList;

typedef LinkedList List;

void InitList(List*); //리스트의 초기화
void LInsert(List*, Ldata);//자료 삽입
int LFirst(List*, Ldata);//첫 자료가 있는가?
int LNext(List*, Ldata);//다음 자료가 있는가?
Ldata LRemove(List*);//자료 삭제
void LPrint(List*);//리스트 자료의 출력
int LCount(List*);//리스트 자료의 개수 반환
void SetSortRule(List*, int (*comp)(Ldata, Ldata));//정렬 규칙 설정
void Rank(List* list);//랭킹 메기기
void Tie_delete(List* list);//동점자 제거


void InitList(List* plist) {
	plist->Head = (Ldata)malloc(sizeof(Node));
	plist->Head->Next = NULL;
	plist->Cur = plist->Before = NULL;
	plist->comp = NULL;
	plist->NumOfData = 0;
}

void LInsert(List* plist, Ldata node) { // Ldata = Node*

	Ldata newNode = node;
	Ldata lHead = plist->Head;

	node->R = 1;

	while (lHead->Next != NULL && plist->comp(node, lHead->Next)) {
		if (node->S == lHead->Next->S && node->N < lHead->Next->N)
			break;
		lHead = lHead->Next;
	}
	newNode->Next = lHead->Next;
	lHead->Next = newNode;

	(plist->NumOfData)++;
}

int LFirst(List* list, Ldata node) {
	if (list->Head->Next == NULL) {
		return 0; 
	}

	list->Before = list->Head;
	list->Cur = list->Head->Next;
	*node = *list->Cur;

	return 1; 
}

int LNext(List* plist, Ldata node) {
	if (plist->Cur->Next == NULL)
		return 0;

	plist->Before = plist->Cur;
	plist->Cur = plist->Cur->Next;
	*node = *plist->Cur;

	return 0;
}

Ldata LRemove(List* plist) {
	Ldata rpos = plist->Cur;
	Ldata rdata = rpos;

	plist->Before->Next = plist->Cur->Next;
	plist->Cur = plist->Before;

	free(rpos);
	(plist->NumOfData)--;
	return rdata;
}

void LPrint(List* plist) {
	Node node;

	if (!LFirst(plist, &node))
		return;
	LFirst(plist, &node);
	printf("-----------------------------\nName Kor Eng Mat Com Sum Rnk\n-----------------------------\n");
	do {
		printf("%c   %3d %3d %3d %3d %3d  %2d\n", node.N, node.K, node.E, node.M, node.C, node.S, node.R);
	} while (LNext(plist, &node));
}

int LCount(List* plist) {
	return plist->NumOfData;
}

void SetSortRule(List* list, int (*comp)(Ldata, Ldata)) {
	list->comp = comp;
}

void Rank(List* plist) {
	Ldata buf;

	LFirst(plist, buf);

	for (int i = 0; i < LCount(plist); i++) {
		if (plist->Before->S == plist->Cur->S)
			plist->Cur->R = plist->Before->R;
		else plist->Cur->R = i + 1;

		LNext(plist, buf);
	}
}

void Tie_delete(List* plist) {
	int count = LCount(plist);

	Ldata buf;

	LFirst(plist, buf);

	for (int i = 0; i < count; i++) {
		if (plist->Before->S == plist->Cur->S)
			LRemove(plist);
		LNext(plist, buf);
	}
}

int Sort_Rule(Ldata x, Ldata y) {
	if (x->S <= y->S)
		return 1;
	else return 0;
}

int main()
{
	List list;
	Ldata newNode;
	FILE* fp;

	fp = fopen("Data.txt", "r");

	InitList(&list);

	list.comp = Sort_Rule;

	if (fp == NULL) {
		printf("파일 열기 실패");
		return 0;
	}

	while (1) {
		newNode = (Node*)malloc(sizeof(Node));
		if (fscanf(fp, " %c %d %d %d %d", &newNode->N, &newNode->K, &newNode->E, &newNode->M, &newNode->C) == EOF) {
			free(newNode);
			break;
		}
		newNode->S = newNode->K + newNode->E + newNode->M + newNode->C;
		LInsert(&list, newNode);
	}

	LPrint(&list);
	Rank(&list);
	LPrint(&list);
	Tie_delete(&list);
	LPrint(&list);

	return 0;
}