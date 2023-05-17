
// 구현 계층
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } // 구현 생략

//---------------------------------------


// 아래 클래스가 중간층(Bridge)

// Point.h
//#include "PointImpl.h"
class PointImpl; // 전방선언만 있으면 포인터 타입은 사용가능

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


// 컴파일 시간 브릿지 기술
// => 컴파일러 방화벽

// => 컴파일 속도가 빨라지고
// => 구현의 헤더가 노출되지 않는다.
//    완벽한 정보 은닉이 가능하다.


// C++IDioms 의
// "PIMPL" 기술
// => Pointer to IMPLementation"