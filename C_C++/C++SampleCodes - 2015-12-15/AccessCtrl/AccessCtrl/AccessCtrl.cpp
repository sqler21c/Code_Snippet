// AccessCtrl.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
	//※ 기본 접근제어 지시자는 'private'이다.
	CMyData() {};
	int m_nData;

public:
	int GetData(void)			{ return m_nData; 	}
	void SetData(int nParam)	{ m_nData = nParam; }
};

//사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData data;
	return 0;
}

