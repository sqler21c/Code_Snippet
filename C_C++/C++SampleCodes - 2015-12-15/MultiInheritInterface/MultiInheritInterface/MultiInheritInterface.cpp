// MultiInheritInterface.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CMyUSB
{
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
public:
	//USB �������̽�
	virtual int GetUsbVersion() { return 0;	}
	virtual int GetTransferRate() { return 0; }
	//�ø��� �������̽�
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyDevice dev;
	return 0;
}

