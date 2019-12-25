// MemberOver.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
public:
	CMyData() : m_nData(0) { };

	int GetData(void) { return m_nData; }
	void SetData(int nParam) {	m_nData = nParam; }
	//실수로 double 형식 인수가 넘어오는 경우를 차단한다.
	void SetData(double dParam) = delete;

private:
	int m_nData;
};

//사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a;
	//CMyData::SetData(int) 메서드가 호출된다.
	a.SetData(10);
	cout << a.GetData() << endl;

	CMyData b;
	//CMyData::SetData(double) 메서드가 호출된다.
	b.SetData(5.5);
	cout << b.GetData() << endl;
	return 0;
}

