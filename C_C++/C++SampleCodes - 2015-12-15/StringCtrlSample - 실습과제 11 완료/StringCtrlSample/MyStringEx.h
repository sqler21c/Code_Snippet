#pragma once
#include "MyString.h"
class CMyStringEx :
	public CMyString
{
public:
	CMyStringEx();
	~CMyStringEx();
	int Find(const char * pszParam);
	virtual void OnSetString(char * pszData, int nLength);
};

