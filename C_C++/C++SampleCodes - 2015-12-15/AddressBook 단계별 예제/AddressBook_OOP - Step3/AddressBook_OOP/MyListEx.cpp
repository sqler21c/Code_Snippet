#include "StdAfx.h"
#include "MyListEx.h"

CMyListEx::CMyListEx(CMyNode *pHead)
: CMyList(pHead)
{
}

CMyListEx::~CMyListEx(void)
{
}

int CMyListEx::OnAddNewNode(CMyNode* pNewNode)
{
	if( strcmp(pNewNode->GetKey(), "������") == 0)
		return 0;

	return 1;
}
