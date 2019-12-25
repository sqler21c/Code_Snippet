// CastSample01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() {}
	virtual ~CMyData() {}
	void SetData(int nParam) { m_nData = nParam; }
	int GetData() { return m_nData;  }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam > 10)	nParam = 10;

		CMyData::SetData(nParam);
	}

	void PrintData()
	{
		cout << "PrintData(): " << GetData() << endl;
		cout << "New data: " << m_nNewData << endl;
	}

	int m_nNewData = 10;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//�Ļ� ���� ��ü�� �⺻ �������� ������ �Ѵ�.
	CMyData *pData = new CMyData;
	CMyDataEx *pNewData = NULL;

	//CMyData::SetData() �Լ��� ȣ���Ѵ�.
	//���� 10�� �Ѵ��� �˻����� �ʴ´�.
	pData->SetData(15);

	//�⺻ ���Ŀ� ���� �������̳� ����Ű�� ����� �Ļ� �����̴�.
	//�� ����� ��Ȯ�ϹǷ� �Ļ� ���Ŀ� ���� �����ͷ� ���ĺ�ȯ�� �õ��Ѵ�.
	pNewData = static_cast<CMyDataEx*> ( pData );
	pNewData->PrintData();
	delete pData;
	return 0;
}

void TestFunc()
{
	int nData = 10;
	char *pszData = NULL;
	pszData = reinterpret_cast<char*> (&nData);
//	pszData = (char*)&nData;
}