#include <iostream>
#include "CMyList.h"

using namespace std;

void printMenu() {
	cout << "---------------------" << endl;
	cout << "CMyList 메뉴" << endl;
	cout << "1 삽입" << endl;
	cout << "2 출력" << endl;
	cout << "0 종료" << endl;
	cout << "---------------------" << endl;
}

int main() {
	CMyList	list;
	printMenu();
	int a;
	int b = 0;
	while (1) {
		cout << "메뉴를 고르세요(숫자 입력) : ";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			cout << "삽입할 데이터를 입력해주세요 :";
			cin >> b;
			list.Insert(b);
			cout << endl;
		case 2:
			list.PrintData();
		case 0:
			break;
		}
	}
	return	0;
}