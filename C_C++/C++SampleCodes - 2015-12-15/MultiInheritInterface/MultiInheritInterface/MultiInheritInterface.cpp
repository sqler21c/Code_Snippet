// MultiInheritInterface.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//USB 인터페이스
	virtual int GetUsbVersion() { return 0;	}
	virtual int GetTransferRate() { return 0; }
	//시리얼 인터페이스
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyDevice dev;
	return 0;
}

