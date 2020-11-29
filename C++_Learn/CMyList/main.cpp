#include <iostream>
#include "CMyList.h"

using namespace std;

int main() {

	char inputData[30];
	CMyList list;
	while (1) {
		consoleInit();
		cin >> inputData;
		if (!strcmp(inputData, "1") && !strcmp(inputData, "2") && !strcmp(inputData, "3")) {
			cout << endl << "0, 1, 2 중 숫자를 입력하세요~!" << endl;
			continue;
		}
		switch ((*inputData) - '0') {
		case 0:
			return 0;
		case 1:
			insertUserData(&list);
			break;
		case 2:
			printUserData(&list);
			break;
		default:
			cout << endl << "0, 1, 2 중 숫자를 입력하세요~!" << endl;
		}
	}

	return 0;
}