// MultiInherit.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyObject
{
public:
	CMyObject() { cout << "CMyObject()" << endl; }
	virtual ~CMyObject() {}
};

class CMyImage : virtual public CMyObject
{
public:
	CMyImage(int nHeight, int nWidth)
		: m_nHeight(nHeight), m_nWidth(nWidth)
	{
		cout << "CMyImage(int, int)" << endl;
	}

	int GetHeight() const { return m_nHeight; }
	int GetWidth() const { return m_nWidth; }
	int GetSize() const { return 0; }

protected:
	int m_nHeight;
	int m_nWidth;
};

class CMyShape : virtual public CMyObject
{
public:
	CMyShape(int nType) : m_nType(nType)
	{
		cout << "CMyShape(int)" << endl;
	}

	int GetType() const { return m_nType; }
	int GetSize() const { return 0; }

protected:
	int m_nType;
};

//�� Ŭ������ ��� ��� �޴´�.
class CMyPicture : public CMyImage, public CMyShape
{
public:
	CMyPicture()
		: CMyImage(200, 120), CMyShape(1)
	{
		cout << "CMyPicture()" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyPicture a;
	//cout << "Width: " << a.GetWidth() << endl;
	//cout << "Height: " << a.GetHeight() << endl;
	//cout << "Type: " << a.GetType() << endl;
	////GetSize() �޼��尡 �� �θ� Ŭ������ ��� �����Ѵ�.
	//a.CMyImage::GetSize();
	//a.CMyShape::GetSize();
	return 0;
}

