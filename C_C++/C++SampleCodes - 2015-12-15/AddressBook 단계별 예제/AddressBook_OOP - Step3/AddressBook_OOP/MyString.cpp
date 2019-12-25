#include "StdAfx.h"
#include "MyString.h"

CMyString::CMyString(void)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString()" << endl;
}

CMyString::CMyString(const char* pszParam)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString(const char*)" << endl;
	SetString( pszParam );
}

CMyString::CMyString(const CMyString & rhs)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString(const CMyString &)" << endl;
	this->SetString( rhs.m_pszData );
}

CMyString::~CMyString(void)
{
//	cout << "~CMyString()" << endl;
	Release();
}

int CMyString::SetString(const char * pszParam)
{
	Release();
	if(pszParam == NULL)	return 0;

	//1. �Ű������� ���޵� ���ڿ��� ���� ����.
	m_nLength = strlen(pszParam);
	if(m_nLength == 0)		return 0;

	//2. �Ű������� ���޵� ���ڿ��� ����� �� �ִ�
	//	 �޸� ���� �Ҵ�.
//	m_pszData = (char*)calloc( m_nLength + 1, sizeof(char) );
	m_pszData = new char [m_nLength + 1];
	//3. ���� �Ҵ��� �޸𸮿� ���ڿ� ����.
	strcpy_s(m_pszData, sizeof(char) * (m_nLength + 1), pszParam);

	//�̷��� �ڵ带 ����.
	OnSetString(m_pszData);

	//���1. ���� �Ű������� NULL�̰ų� ���ڿ��� ���̰�
	//		  0�̶��, � ó���� �����Ѱ�?
	//���2. ���� �Ҵ�� �޸𸮴� ���� ��� �����ϴ°�.
	//���3. ���� ����ڿ� ���� �� �Լ��� 2ȸ ȣ��ȴٸ�
	//		  ���� �ۼ��� �ڵ忡 ������ ���°�?
	return m_nLength;
}

void CMyString::Release(void)
{
	//1. m_pszData����� ����Ű�� �޸𸮸� ����.
	delete [] m_pszData;
	//2. �޼����� �������� ȣ�� ������ ����ڰ�
	//	 �����Ѵ�. �׷��Ƿ� �޸𸮸� ������
	//	 ���ķ� � �ڵ尡 �߰��Ǿ�� �̾�����
	//	 ����� �ڵ��� ������ �帧�� ������
	//	 ���� ���� �� �ִ°�?
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator =(const CMyString &strParam)
{
	if(this != &strParam)
		SetString(strParam.m_pszData);

	return *this;
}

CMyString& CMyString::operator =(const char * pszParam)
{
	if(this->m_pszData != pszParam)
		SetString(pszParam);

	return *this;
}

CMyString CMyString::operator +(const CMyString & rhs)
{
	CMyString strResult(*this);
	strResult.Append(rhs.m_pszData);
	return strResult;
}

int CMyString::Append(const char* pszParam)
{
	if(pszParam == NULL)	return 0;

	int nLenParam = strlen(pszParam);
	if(nLenParam == 0)		return 0;

	if(m_pszData != NULL)
	{
		int nLenResult = m_nLength + nLenParam;
		char *pszResult = new char[nLenResult + 1];
		strcpy_s(pszResult, m_nLength + 1, m_pszData);
		strcpy_s(pszResult + m_nLength, nLenParam + 1, pszParam);

		Release();
		m_pszData = pszResult;
		m_nLength = nLenResult;
	}
	else
	{
		this->operator = (pszParam);
	}
	return 0;
}

CMyString CMyString::operator +(const char* pszParam)
{
	CMyString strResult(*this);
	strResult.Append(pszParam);
	return strResult;
}

//�����Լ�
CMyString operator + (const char *pszLeft, const CMyString & strRight)
{
	CMyString strResult(pszLeft);
	strResult.Append(strRight.m_pszData);
	return strResult;
}

int CMyString::TestFunc(const char* pszParam)
{
	return SetString(pszParam);
}

int CMyString::OnSetString(const char *pszParam)
{
	return 1;
}
