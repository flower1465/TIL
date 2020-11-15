#include <iostream>
#include "CMyString.h"
#include "CMyStringEX.h"

using namespace	std;
int	main()
{
	CMyStringEx	strTest;

	strTest.SetString("학번 : 1204, 이름 : 박승준");	// 학번과 이름은	 본인 것으로 수정!!!

	cout << strTest << endl;

	int	nIndex = strTest.Find("박승준");	// 본인 이름으로 수정

	cout << "Index : " << nIndex << endl;

	return	0;
}











//8번
//#include <iostream>
//#include "CMyString.h"
//
//using namespace std;
//
//int	main()
//{
//	CMyString strParam("StudentID : 1204"), strName("Name: 박승준");	//	학번,이름은	본인	것으로	수정
//	
//	if (strParam == strName)
//		cout << "같다!	" << endl;
//	else
//		cout << "다르다!	" << endl;
//
//	CMyString	strTest = CMyString("StudentID : 1204");	//	학번은	본인	것으로	수정
//	if (strParam != strTest)
//
//		cout << "다르다!" << endl;
//	else
//		cout << "같다!	" << endl;
//
//	return	0;
//}


//7번
//#include	<iostream>
//#include	"CMyString.h"
//
//using namespace	std;
//
//void TestFunc(const	CMyString& strParam)
//{
//	for (int i = 0; i < strParam.GetLength(); i++)
//	{
//		cout << strParam[i] << " ";
//	}
//	cout << endl;
//}
//
//int	main()
//{
//	CMyString strParam("StudentID : 1204, Name : 박승준");	//	학번과	이름은	본인	것으로	수정
//	
//	cout << strParam.GetString() << endl;
//	
//	TestFunc(strParam);
//
//	return	0;
//}





//6번
//#include	<iostream>
//#include	"CMyString.h"
//
//using namespace std;
//
//int	main()
//{
//	CMyString	strLeft("학번 : 1204"), strRight(", 이름 : 박승준"), strResult;	//	학번과	이름은	본인	것으로	수정
//	strResult = strLeft + strRight;
//	cout << strResult << endl;
//	cout << strLeft << endl;
//	strLeft += strRight;
//	cout << strLeft << endl;
//
//	return	0;
//}





// 5번
//#include	<iostream>
//#include	"CMyString.h"
//
//using	namespace	std;
//
//CMyString	TestFunc()
//{
//	CMyString	strTest("TestFunc()	return");
//	cout << strTest << endl;
//	return	strTest;
//}
//
//int	main()
//{
//	//	이름없는	임시	객체가	만들어진다.
//	TestFunc();
//	return	0;
//}







// 4번
//#include	<iostream>
//#include	"CMyString.h"
//
//using	namespace	std;
//
//void	TestFunc(const	CMyString& strParam)
//{
//	cout << strParam << endl;
//}
//
//int	main()
//{
//	CMyString	strData("Hello");
//
//	::TestFunc(strData);
//	::TestFunc(CMyString("World"));
//	
//	return	0;
//}
















// 3번
//#include	<iostream>
//#include	"CMyString.h"
//
//using namespace	std;
//
//void TestFunc(const	CMyString& param)
//{
//	cout << param.GetString() << endl;
//}
//
//int	main()
//{
//	CMyString	strData, strTest;
//	
//	strData.SetString("Hello");
//	strTest.SetString("World");
//	
//	//	복사	생성
//	CMyString	strNewData(strData);
//	cout << strNewData.GetString() << endl;
//	
//	//	단순	대입	연산자	호출
//	CMyString str2;
//	str2 = strTest;
//	cout << str2.GetString() << endl;
//	/*strNewData = strTest;
//	cout << strNewData.GetString() << endl;*/
//	
//	return	0;
//}


//#include	<iostream>
//#include	"CMyString.h"
//#include "../Instance/instance.cpp"
//
//using	namespace	std;
//
//int main()
//{
//	CMyString strData;
//
//	cout << strData.GetString() << endl;
//
//	strData.Release();
//
//	cout << strData.GetString() << endl;
//
//	CMyString strData2;
//
//	strData2.SetString("");
//
//	cout << strData2.GetString() << endl;
//
//	strData2.Release();
//
//	CMyString strData3;
//
//	strData3.SetString("Hello");
//
//	TestFunc(strData3);
//
//	cout << strData3.GetString() << endl;
//
//	strData3.Release();
//
//	return	0;
//}