#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CMyList.h"

using namespace std;

class CMyListEx : public CMyList {
public:

	CMyListEx(int num) : CMyList(num) {}
	~CMyListEx();

	void ShowMenu();
	void InsertFront();
	void InsertDataFront(int data);
	void InsertBack();
	void DeleteFront();
	void DeleteBack();
	void PrintReverse();
};