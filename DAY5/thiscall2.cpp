#include <functional> 

class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};
void foo(int a) {} 

int main()
{
	void(*f1)(int) = &foo;	// ok				
	void(*f2)(int) = &Dialog::Close; // error
								// Close 는 this가 추가되는 함수

	void(*f3)(int) = &Dialog::Close2; // ok

	// 핵심 
	// 1. 일반 함수포인터에는        멤버 함수의 주소를 담을수 없습니다.
	// 2. 일반 함수포인터에는 static 멤버 함수의 주소를 담을수 있습니다.


	// 아래 문법이 멤버 함수 포인터 입니다.
	void(Dialog::*f4)(int) = &Dialog::Close; // ok

	// 아래 처럼하면 안되나요 ??? => 안됩니다. 위 처럼 해야 합니다.
	void(*f4)(Dialog*, int) = &Dialog::Close;


	p1.set(10, 20); // set(&p1, 10, 20) 으로 이야기 하는데..
					// 실제 인자와 객체가 전달되는 방식이
					// 컴파일러에 따라 다릅니다.
					// push	20
					// push	10
					// mov ecx, &p1		// this
					// call Point::set
}






