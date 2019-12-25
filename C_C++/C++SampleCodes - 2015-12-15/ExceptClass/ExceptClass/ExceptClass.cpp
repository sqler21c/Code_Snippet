// ExceptClass.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyException
{
public:
	//예외 코드와 메시지를 입력 받는다.
	CMyException(int nCode, const char *pszMsg)
	{
		m_nErrorCode = nCode;
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const { return m_nErrorCode; }
	const char* GetMessage() const { return m_szMsg; }

private:
	int m_nErrorCode;
	char m_szMsg[128];
};

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		int nInput = 0;
		cout << "양의 정수를 입력하세요.: ";
		cin >> nInput;
		if (nInput < 0)
		{
			CMyException exp(10, "양의 정수를 입력해야 합니다.");
			throw exp;
		}
	}
	catch (CMyException &exp)
	{
		cout << "ERROR CODE [" << exp.GetErrorCode() << "] " <<
			exp.GetMessage() << endl;
	}
	return 0;
}

