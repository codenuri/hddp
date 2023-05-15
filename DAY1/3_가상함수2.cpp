#include <iostream>

class Base
{
public:
	virtual ~Base() {} // 기반 클래스는 반드시 소멸자를						// 가상함수로 해야 합니다.
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	 ~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	// 생성자 호출
//	delete p;					// 소멸자 호출

	// 핵심 : 아래 코드 결과 확인해 보세요
	Base* p = new Derived;
	delete p;	// 1. 소멸자 호출
				// 2. 메모리 삭제
	// 소멸자 호출도 "결국 함수 호출" 입니다
	// 
	// 1. 소멸자가 가상인지 조사해야 합니다.
	//    => p 가 Base* 이므로 Base 클래스를 조사

	// 소멸자가 가상이 아니면 : ~Base() 만호출
	// 소멸자가 가상이면     : p가 가리키는 객체의 타입을 조사후
	//						호출

}	
