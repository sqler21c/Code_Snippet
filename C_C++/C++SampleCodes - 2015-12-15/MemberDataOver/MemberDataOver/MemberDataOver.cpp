// MemberDataOver.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//초기 제작자
class CMyData
{
public:
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected:
	//파생 형식에서 접근할 수 있다.
	int m_nData = 0;
};

//후기 제작자
class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam > 10)	nParam = 10;
		//※ 파생 형식의 m_nData에 접근하는 것이다!
		m_nData = nParam;
	}

protected:
	//파생 형식에서 기본 형식과 같은 멤버를 재정의했다.
	int m_nData = 0;
};

//사용자
int _tmain(int argc, _TCHAR* argv[])
{
	CMyDataEx a;
	a.SetData(15);
	cout << a.GetData() << endl;
	return 0;
}

