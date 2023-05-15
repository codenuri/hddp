//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	
	// 사용자 코드		// 컴파일러가 변경한것
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl;
	}
	Derived(int a)		// Derived(int a) : Base()
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{
		std::cout << "~Derived()" << std::endl; 

		// ~Base();  // 소멸자는 Derived 구현을 먼저 실행후에
					 // Base 소멸자 호출
	}
};
int main()
{
//	Derived d1;
	Derived d2(5); // call Derived::Derived(int) 호출

}







// DAY1.zip 압축 풀러 보세요
// DAY1.sln 파일 더블클릭해서 여시면 됩니다.

// 1. 버전 설정해야 합니다.
//    => 프로젝트 메뉴, 속성 메뉴 선택
// 
// 2. Ctrl + F5 로 빌드 되는지 확인해 보세요
// 3. 소스를 빌드에 포함/제외 하는 방법

// 교재
// 1. C++ 문법 정리
// 2. 강의에서 다루는 다양한 예제들
// 3. 디자인패턴 23개 정리!