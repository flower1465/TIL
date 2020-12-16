#include "CMyListEx.h"


CMyListEx::~CMyListEx() {}

void CMyListEx::ShowMenu() {
	puts("---------------------");
	puts("CMyList 메뉴");
	puts("1 삽입 Head");
	puts("2 삽입 Tail");
	puts("3 삭제 Head");
	puts("4 삭제 Tail");
	puts("5 출력 Head -> Tail");
	puts("6 출력 Tail -> Head");
	puts("0 종료");
	puts("---------------------");
	cout << "메뉴를 고르세요(숫자 입력): ";
}
void CMyListEx::InsertFront() {
	if (GetCount() >= GetLength()) {
		cout << "설정하신 길이를 넘으셨습니다.";
		return;
	}
	int data = 0;
	cout << "삽입할 데이터를 입력해주세요 : ";
	cin >> data;
	cout << endl;
	InsertDataFront(data);
}
void CMyListEx::InsertDataFront(int data) {
	Node* newNode = new Node;
	Node* pHead = GetHead();

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (pHead == NULL) {
		SetTail(newNode);
	}
	else {
		pHead->prev = newNode;
		newNode->next = pHead;
	}
	SetHead(newNode);
	SetPCount();
	Print();
}
void CMyListEx::InsertBack() {
	Insert();
}
void CMyListEx::DeleteFront() {
	Node* DelNode = GetHead();

	if (DelNode == nullptr) {
		cout << endl << "삭제할 데이터가 없습니다." << endl << endl;
	}
	else {
		Node* DelNext = DelNode->next;

		if (SetHead(DelNext)) {
			DelNode->next = nullptr;
			DelNode->prev = nullptr;

			delete DelNode;

			SetMCount();

			Print();

			return;
		}

		DelNode->next = NULL;
		DelNext->prev = NULL;

		delete DelNode;

		SetMCount();

		Print();
	}
}
void CMyListEx::DeleteBack() {
	Node* DelNode = GetTail();

	if (DelNode == nullptr) {
		SetHead(DelNode);
		cout << endl << "삭제할 데이터가 없습니다." << endl << endl;
	}
	else {
		Node* DelPrev = DelNode->prev;

		if (SetTail(DelPrev)) {
			DelNode->next = nullptr;
			DelNode->prev = nullptr;

			delete DelNode;

			SetMCount();

			Print();

			return;
		}

		DelNode->prev = NULL;
		DelPrev->next = NULL;

		delete DelNode;

		SetMCount();

		Print();
	}
}
void CMyListEx::PrintReverse() {
	Node* curNode = new Node;
	curNode = GetTail();

	cout << "CMyList 데이터 : [Head] ";
	if (GetLength() == 0) {
		return;
	}
	for (int i = 0; i < GetLength() - 1; i++) {
		cout << curNode->data << " - ";
		curNode = curNode->prev;
	}
	cout << curNode->data;
	cout << " [Tail]" << endl;
	cout << "데이터 개수" << GetLength() << "개" << endl << endl;
}