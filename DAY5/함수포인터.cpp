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
	// 1. 멤버 함수 주소 담기
	void(Dialog::*f4)(int) = &Dialog::Close; 

	// 2. 멤버 함수 포인터로 함수 호출하기 - 핵심!!
	f4(10); // error. 객체가 없다.

	Dialog dlg;
//	dlg.f4(10); // error. dlg 안에 f4라는 멤버 없습니다.

	// .* 연산자 "pointer to member operator" 라는 연산자
	//			 C++ 전용 연산자
	//dlg.*f4(10); // error. 연산자 우선순위가 .* 보다 ( 빠르다.

	(dlg.*f4)(10); // ok.. 멤버 함수 포인터로 멤버 함수를 
					// 호출하는 코드.
	
	// 일반 함수 포인터 사용법 : f1(10)
	// 멤버 함수 포인터 사용법 : (dlg.*f4)(10)

	// 모든 호출 가능한 객체를 일관성있게 사용하자
	std::invoke(f1, 10); // f1(10)
	std::invoke(f4, &dlg, 10); // (dlg.*f4)(10)

	// => C++17 이고  <functional>
}

// 복습하시다면 질문은 smkang @ codenuri.co.kr

