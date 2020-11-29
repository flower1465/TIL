#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class CMyList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	CMyList() {}
	~CMyList() {
		FreeListData();
	}
	void InsertListData(Node* newNode) {
		if (head == nullptr) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
	}
	void PrintListData() {
		Node* curNode = this->head;
		int nodeCount = 1;

		cout << endl << "CMyList 데이터 : ";
		while (curNode->next != nullptr) {
			cout << curNode->data << " - ";
			curNode = curNode->next;
			nodeCount++;
		}
		cout << curNode->data << "  " << nodeCount << "개" << endl;
	}
	int isOverLappingData(int testData) {
		Node* curNode = this->head;
		while (curNode != nullptr) {
			if (curNode->data == testData) {
				return 1;
			}
			curNode = curNode->next;
		}
		return 0;
	}
	int isEmpty() {
		if (this->head == nullptr) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void FreeListData() {
		Node* curNode = this->head;
		Node* delNode;
		while (curNode != nullptr) {
			delNode = curNode;
			curNode = curNode->next;
			delete delNode;
		}
	}
};

void consoleInit() {
	puts("---------------------");
	puts("CMyList 메뉴");
	puts("1 삽입");
	puts("2 출력");
	puts("0 종료");
	puts("---------------------");
	cout << "메뉴를 고르세요(숫자 입력): ";
}

void insertUserData(CMyList* list) {
	int inputData;
	Node* newNode = new Node;
	while (1) {
		cout << endl << "삽입할 데이터를 입력해주세요 : ";
		cin >> inputData;
		if ((list->isOverLappingData(inputData))) {
			cout << inputData << "는 중복입니다!" << endl;
			continue;
		}
		newNode->data = inputData;
		newNode->next = nullptr;
		break;
	}
	list->InsertListData(newNode);
	list->PrintListData();
}

void printUserData(CMyList* list) {
	if (list->isEmpty()) {
		cout << endl << "출력할 데이터가 없습니다." << endl;
		return;
	}
	list->PrintListData();
}