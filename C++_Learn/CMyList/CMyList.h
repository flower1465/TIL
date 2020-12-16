#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class CMyList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	static int m_nLength;
	int count;
public:
	CMyList(); 
	CMyList(int num);
	~CMyList();
	virtual void ShowMenu() const;
	void Insert();
	void InsertData(int data);
	void Print();
	void DeleteList();
	Node* GetHead();
	bool SetHead(Node* phead);
	Node* GetTail();
	bool SetTail(Node* ptail);
	int GetLength();
	void SetPLength();
	void SetMLength();
	void SetLenght(int lenght);
	void SetPCount();
	void SetMCount();
	int GetCount();
	CMyList& operator+=(const int&);
};