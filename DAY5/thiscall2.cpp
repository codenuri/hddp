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
}






