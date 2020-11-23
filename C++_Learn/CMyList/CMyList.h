#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class CMyList {
public:
	CMyList() {

	}
	~CMyList() {
		FreeNode();
	}
	void Insert(int num) {
		Node* newNode;
		newNode = new Node;
		newNode->data = num;
		newNode->next = this->pHead;
		this->pHead = newNode;
	}
	void PrintData() {
		Node* curNode = this->pHead;
		int nodeCount = 1;

		if (curNode == nullptr) {
			cout << "리스트가 없어연" << endl;
			return;
		}

		cout << "CMyList 데이터 : ";
		while (curNode->next != nullptr) {
			cout << curNode->data << " - ";
			curNode = curNode->next;
			nodeCount++;
		}
		cout << curNode->data << "  " << nodeCount << "개" << endl;
	}
	void FreeNode() {
		Node* curNode = this->pHead;
		Node* delNode;
		while (curNode != nullptr) {
			delNode = curNode;
			curNode = curNode->next;
			delete delNode;
		}
	}
private:
	Node* pHead = nullptr;
	Node* pTael = nullptr;
};