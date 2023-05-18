
// ���� ����
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } // ���� ����

//---------------------------------------


// �Ʒ� Ŭ������ �߰���(Bridge)

// Point.h
//#include "PointImpl.h"
class PointImpl; // ���漱�� ������ ������ Ÿ���� ��밡��

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// ������ �ð� �긴�� ���
// => �����Ϸ� ��ȭ��

// => ������ �ӵ��� ��������
// => ������ ����� ������� �ʴ´�.
//    �Ϻ��� ���� ������ �����ϴ�.


// C++IDioms ��
// "PIMPL" ���
// => Pointer to IMPLementation"