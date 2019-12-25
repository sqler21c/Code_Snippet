// ImTypeCast.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CTestData
{
public:
	//매개변수가 하나뿐인 생성자는 형식 변환이 가능하다.
	//하지만 묵시적으로는 불가능하도록 차단한다.
	explicit CTestData(int nParam) : m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	~CTestData()
	{
		cout << "~CTestData()" << endl;
	}

	CTestData(const CTestData &rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

//사용자 코드
//매개변수가 클래스에 대한 참조 형식이며 묵시적으로 변환 생성된다.
void TestFunc(const CTestData &param)
{
	cout << "TestFunc(): " << param.GetData() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	//새로운 CTestData 객체를 생성하고 참조로 전달한다.
	TestFunc( CTestData(5) );
	//함수가 반환하면서 임시객체는 소멸한다.
	cout << "******End******" << endl;
	return 0;
}

