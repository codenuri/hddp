#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 

	// 가상함수가 아니면 : 포인터 타입으로 호출
	// 가상함수 라면    : 실행시간에 객체의 타입을 조사해서 호출
	//					단, 가상함수는 오버헤드가 있습니다.
	
	// virtual : 함수 호출시 컴파일러가 어떤 기계어를 만들지를
	//			알려 주는것

	p->cry(); // 1. 이 순간 p의 타입을 조사
			  // 2. p는 Animal* 입니다.
			  // 3. Animal 클래스에서 cry 가 virtual 인지조사

	// => virtual 이 아니면 "call Animal::cry" 기계어 생성
	// => virtual 이면 
	//  "p가 가리키는 메모리가 어떤 타입의 객체인지 
	//  "조사하는 기계어 코드 생성" 
	//  "위 결과에 따라 cry() 함수 호출"
}


