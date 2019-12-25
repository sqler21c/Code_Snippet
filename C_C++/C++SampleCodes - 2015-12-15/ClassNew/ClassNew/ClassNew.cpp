// ClassNew.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest::CTest()" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;
	//배열로 new 연산을 수행할 수 있다.
	CTest *pData = new CTest[3];
	//배열로 생성한 것은 반드시 배열로 삭제한다!
	delete [] pData;
	cout << "End" << endl;
	return 0;
}

