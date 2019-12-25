// CastSample01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//파생 형식 객체를 기본 형식으로 포인팅 한다.
	CMyData *pData = new CMyData;
	CMyDataEx *pNewData = NULL;

	//CMyData::SetData() 함수를 호출한다.
	//따라서 10이 넘는지 검사하지 않는다.
	pData->SetData(15);

	//기본 형식에 대한 포인터이나 가리키는 대상은 파생 형식이다.
	//이 사실이 명확하므로 파생 형식에 대한 포인터로 형식변환을 시도한다.
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