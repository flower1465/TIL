//#include "CMyList.h"
//
//using namespace std;

//int	main()
//{
//	CMyList* myList = new CMyList;
//	int	num;
//	
//	while (1)
//	{
//		myList->ShowMenu();
//		cin >> num;
//		cout << endl;
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(10000, '\n');
//			cout << " 0, 1, 2 중 숫자를 입력하세요~!\n";
//			continue;
//		}
//		switch (num)
//		{
//		case 0:
//			cout << "종료합니다!\n";
//			delete myList;
//			return 0;
//		case 1:
//			myList->Insert();
//			break;
//		case 2:
//			myList->Print();
//			break;
//		default:
//			cout << " 0, 1, 2 중	 숫자를 입력하세요~!\n";
//			continue;
//		}
//	}
//	return	0;
//}

//CMyListExㄴ
#include "CMyListEx.h"

int	main()
{

	int	num;
	int lenght;

	cout << "길이를 정해주십시오";
	cin >> lenght;
	CMyListEx* myListex = new CMyListEx(lenght);

	while (1)
	{
		myListex->ShowMenu();
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << " 0, 1, 2, 3, 4, 5, 6 중 숫자를 입력하세요~! : ";
			continue;
		}
		switch (num)
		{
		case 0: cout << " 종료합니다!\n";
			delete	myListex;
			return	0;
		case 1: myListex->InsertFront();
			break;
		case 2: myListex->InsertBack();
			break;
		case 3: myListex->DeleteFront();
			break;
		case 4: myListex->DeleteBack();
			break;
		case 5: myListex->Print();
			break;
		case 6: myListex->PrintReverse();
			break;
		default:
			cout << " 0, 1, 2, 3, 4, 5, 6 중	 숫자를 입력하세요~! : ";
			continue;
		}
	}
	return	0;
}