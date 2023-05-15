//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	// 핵심 : Base 에 디폴트 생성자가 없습니다.
	Base(int a) { }
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()	{}		// Derived()      : Base() {}
	Derived(int a)	{}	// Derived(int a) : Base() {}

	~Derived() {	}
};
int main()
{
	//	Derived d1;
	Derived d2(5); 

}




