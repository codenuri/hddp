#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 기반 클래스는 반드시 소멸자를
						// 가상함수로 만들어야 합니다.
						// 조금있다가 설명..
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a; // 객체 자체가 Animal 입니다

	Animal* p = &a;

//	if (사용자 입력 == 1) p = new Dog;

	// 아래 코드는 어떻게 될까요 ?
	// static_cast : 컴파일 시간 캐스팅
	//			     p가 가리키는 곳을 조사할수 없습니다.
	// 아래 결과로 나오는 pd를 가지고
	// "pd->color = 20" 등의 코드를 사용하면 안됩니다.
//	Dog* pd = static_cast<Dog*>(p);


	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p가 가리키는 메모리를 조사후캐스팅 
	// 단, dynamic_cast는 다형적 타입(가상함수가 있는)만 사용가능
	// 합니다.
	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











