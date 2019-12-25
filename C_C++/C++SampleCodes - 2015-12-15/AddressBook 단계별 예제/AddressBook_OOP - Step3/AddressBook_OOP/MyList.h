#pragma once
#include "MyNode.h"
#include "MyIterator.h"

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList(void);

protected:
	void ReleaseList(void);
	CMyNode *m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode *pNewNode);
	//UI�ڵ��̴�. ����� �ٶ������� �ʴ�.
//	void PrintAll(void);
	int RemoveNode(const char* pszKey);
	CMyIterator MakeIterator(void);

	virtual int OnAddNewNode(CMyNode* pNewNode);
};
