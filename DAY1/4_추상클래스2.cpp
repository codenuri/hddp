//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능확장에는 열려 있고( Open, 클래스가 추가되어도)
// 코드수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 해야 한다는 이론(Principle)

// Open-Close Principle 
// 아래 코드는 OCP를 만족할수 없는 코드 입니다.

// SOLID : 객체 지향 프로그램이 지켜야 하는 5가지 원칙
// => SRP, OCP, LSP, ISP, DIP




class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);
}





