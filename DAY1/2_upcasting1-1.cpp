#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {} // ��� Ŭ������ �ݵ�� �Ҹ��ڸ�
						// �����Լ��� ������ �մϴ�.
						// �����ִٰ� ����..
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

//	if (����� �Է� == 1) p = new Dog;

	// �Ʒ� �ڵ�� ��� �ɱ�� ?
	// static_cast : ������ �ð� ĳ����
	//			     p�� ����Ű�� ���� �����Ҽ� �����ϴ�.
	// �Ʒ� ����� ������ pd�� ������
	// "pd->color = 20" ���� �ڵ带 ����ϸ� �ȵ˴ϴ�.
//	Dog* pd = static_cast<Dog*>(p);


	// dynamic_cast : ����ð� ĳ����
	//				  ����ð��� p�� ����Ű�� �޸𸮸� ������ĳ���� 
	// ��, dynamic_cast�� ������ Ÿ��(�����Լ��� �ִ�)�� ��밡��
	// �մϴ�.
	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;

}











