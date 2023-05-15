#include <iostream>

class Animal
{
public:
	int age;
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

	// 아래 코드는 어떻게 될까요 ?
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











