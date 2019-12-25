// VirtualDestructor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
public:
	CMyData() { m_pszData = new char[32]; }
	//소멸자를 가상 함수로 선언
	virtual ~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pszData;
	}

private:
	char *m_pszData;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { m_pnData = new int; }
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
		delete m_pnData;
	}

private:
	int *m_pnData;
};

//사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData *pData = new CMyDataEx;
	//소멸자가 가상화 되면 실형식의 소멸자가 호출된다.
	delete pData;
	return 0;
}

