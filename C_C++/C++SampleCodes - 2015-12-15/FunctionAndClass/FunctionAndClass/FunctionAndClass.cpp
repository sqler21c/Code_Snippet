// FunctionAndClass.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData &rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	//�б� ������ ����� �޼���.
	int GetData() const { return m_nData; }
	//����� ���⸦ �õ��ϴ� �޼���.
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

//�Ű������� CTestData Ŭ���� �����̹Ƿ� ���� �����ڰ� ȣ��ȴ�.
void TestFunc(CTestData param)
{
	cout << "TestFunc()" << endl;
	//��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� �����Ѵ�.
	param.SetData(20);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	CTestData a(10);
	TestFunc(a);
	//�Լ� ȣ�� �� a�� ���� ����Ѵ�.
	cout << "a: " << a.GetData() << endl;
	cout << "******End******" << endl;
	return 0;
}
