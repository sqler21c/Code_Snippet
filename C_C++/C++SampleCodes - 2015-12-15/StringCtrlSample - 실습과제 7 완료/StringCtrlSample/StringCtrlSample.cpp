// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;

	strLeft = CMyString("String");
	if (strLeft != strRight)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;
	return 0;
}

