#include "CMyList.h"

int CMyList::m_nLength;

CMyList::CMyList(int num) {
	this->m_nLength = num;
}
CMyList::~CMyList() {
	DeleteList();
}

void CMyList::ShowMenu() const {
	puts("---------------------");
	puts("CMyList 메뉴");
	puts("1 삽입");
	puts("2 출력");
	puts("0 종료");
	puts("---------------------");
	cout << "메뉴를 고르세요(숫자 입력) : ";
}
void CMyList::Insert() {
	if (count >= m_nLength ) {
		cout << "설정하신 길이를 넘으셨습니다.";
		return;
	}
	int data = 0;
	cout << "삽입할 데이터를 입력해주세요 : ";
	cin >> data;
	cout << endl;
	InsertData(data);
}
void CMyList::InsertData(int data) {
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (GetHead() == nullptr) {
		head = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
	}
	tail = newNode;
	count++;
	Print();
}
void CMyList::Print() {
	Node* curNode = head;

	if (curNode == NULL) {
		return;
	}
	cout << "CMyList 데이터 : [Head] ";

	while (curNode != nullptr) {
		if (count == 1) {
			cout << curNode->data;
			break;
		}
		else {
			cout << curNode->data;

			if (curNode->next == nullptr) break;

			curNode = curNode->next;

			cout << " - ";
		}
	}
	cout << " [Tail]" << endl;
	//cout << curNode->data;
	cout << "데이터 개수" << count << "개" << endl << endl;
}

void CMyList::DeleteList() {
	Node* DelNode = head;
	Node* DelNext = DelNode->next;
	
	cout << endl << "소멸자 호출됨" << endl;

	if (GetLength() == 0) {
		cout << endl << "삭제할 노드가 없습니다." << endl << endl;
	}
	else {
		cout << endl;
		while (DelNode != NULL) {
			cout << DelNode->data << endl;

			delete DelNode;

			if (DelNext == nullptr) {
				break;
			}
			DelNode = DelNext;
			DelNext = DelNext->next;
		}
	}
}

Node* CMyList::GetHead(){
	return this->head;
}
bool CMyList::SetHead(Node* phead) {
	if (phead == nullptr) {
		this->head = this->tail = nullptr;

		return true;
	}

	this->head = phead;

	return false;
}
Node* CMyList::GetTail(){
	return this->tail;
}
bool CMyList::SetTail(Node* ptail) {
	if (ptail == nullptr)
	{
		this->tail = this->head = nullptr;

		return true;
	}

	this->tail = ptail;

	return false;
}
int CMyList::GetLength(){
	return this->m_nLength;
}
void CMyList::SetPLength() {
	this->m_nLength++;
}
void CMyList::SetMLength() {
	this->m_nLength--;
}
void CMyList::SetLenght(int lenght) {
	this->m_nLength = lenght;
}
int CMyList::GetCount() {
	return this->count;
}
void CMyList::SetPCount() {
	this->count++;
}
void CMyList::SetMCount() {
	this->count--;
}
CMyList& CMyList::operator+=(const int& data) {
	this->InsertData(data);
	return *this;
}