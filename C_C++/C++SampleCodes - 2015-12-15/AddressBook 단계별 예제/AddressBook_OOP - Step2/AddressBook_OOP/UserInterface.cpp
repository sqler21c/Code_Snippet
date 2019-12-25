#include "StdAfx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

CUserInterface::CUserInterface(CMyList &rList)
: m_List(rList)
{
}

CUserInterface::~CUserInterface(void)
{
}

void CUserInterface::Add(void)
{
	char szName[32] = {0};
	char szPhone[32] = {0};

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");
	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	m_List.AddNewNode( new CUserData(szName, szPhone) );
}

void CUserInterface::Search(void)
{
	char szName[32] = {0};
	CUserData *pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = static_cast<CUserData*>( m_List.FindNode(szName) );
	if(pNode != NULL)
	{
		pNode->PrintNode();
	}
	else
	{
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}

	_getch();
}

void CUserInterface::Remove(void)
{
	char szName[32] = {0};

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName) );

	m_List.RemoveNode(szName);
}

int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf_s("%d", &nInput);
	return nInput;
}

int CUserInterface::Run(void)
{
	int nMenu = 0;
	while( (nMenu = PrintUI()) != 0 )
	{
		switch(nMenu)
		{
		case 1:		//Add
			Add();
			break;

		case 2:		//Search
			Search();
			break;

		case 3:		//Print all
			m_List.PrintAll();
			break;

		case 4:		//Remove
			Remove();
			break;
		}
	}

	return nMenu;
}
