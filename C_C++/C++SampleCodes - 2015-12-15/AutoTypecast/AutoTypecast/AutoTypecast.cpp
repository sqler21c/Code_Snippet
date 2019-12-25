// AutoTypecast.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//������ �ڵ�
class CTestData
{
public:
	explicit CTestData(int nParam) : m_nData(nParam) { }
	//CTestData Ŭ������ int�������� ��ȯ�� �� �ִ�!
	explicit operator int(void) { return m_nData;  }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

//����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CTestData a(10);
	cout << a.GetData() << endl;
	//CTestData���� int�� ��ȯ�� �� �ִ�.
	cout << a << endl;
	cout << (int)a << endl;
	cout << static_cast<int>( a ) << endl;
	return 0;
}

