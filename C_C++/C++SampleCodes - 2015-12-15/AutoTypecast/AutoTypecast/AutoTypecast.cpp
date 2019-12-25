// AutoTypecast.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CTestData
{
public:
	explicit CTestData(int nParam) : m_nData(nParam) { }
	//CTestData 클래스는 int형식으로 변환될 수 있다!
	explicit operator int(void) { return m_nData;  }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

//사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CTestData a(10);
	cout << a.GetData() << endl;
	//CTestData에서 int로 변환될 수 있다.
	cout << a << endl;
	cout << (int)a << endl;
	cout << static_cast<int>( a ) << endl;
	return 0;
}

