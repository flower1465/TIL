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

		cout << endl << "CMyList ������ : ";
		while (curNode->next != nullptr) {
			cout << curNode->data << " - ";
			curNode = curNode->next;
			nodeCount++;
		}
		cout << curNode->data << "  " << nodeCount << "��" << endl;
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
	puts("CMyList �޴�");
	puts("1 ����");
	puts("2 ���");
	puts("0 ����");
	puts("---------------------");
	cout << "�޴��� ������(���� �Է�): ";
}

void insertUserData(CMyList* list) {
	int inputData;
	Node* newNode = new Node;
	while (1) {
		cout << endl << "������ �����͸� �Է����ּ��� : ";
		cin >> inputData;
		if ((list->isOverLappingData(inputData))) {
			cout << inputData << "�� �ߺ��Դϴ�!" << endl;
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
		cout << endl << "����� �����Ͱ� �����ϴ�." << endl;
		return;
	}
	list->PrintListData();
}