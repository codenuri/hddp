#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// 핵심 1. 각 도형을 타입으로 설계하면 편리하다.
// 
// 핵심 2. 모든 도형의 기반 클래스가 있다면 모든 도형을
//        하나의 컨테이너에 묶어서 관리할수 있다.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w,h 과 생성자등은 생략..
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v1; // Rect 객체만 보관 가능
//	std::vector<Circle*> v2;

	std::vector<Shape*> v; // 모든 도형을 하나의 컨테이너에
							// 묶어서 보관!!
}

