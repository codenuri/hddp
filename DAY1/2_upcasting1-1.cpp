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
	Animal a; // ��ü ��ü�� Animal �Դϴ�

	Animal* p = &a;

	// �Ʒ� �ڵ�� ��� �ɱ�� ?
	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











