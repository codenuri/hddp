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

	// �����Լ��� �ƴϸ� : ������ Ÿ������ ȣ��
	// �����Լ� ���    : ����ð��� ��ü�� Ÿ���� �����ؼ� ȣ��
	//					��, �����Լ��� ������尡 �ֽ��ϴ�.
	
	// virtual : �Լ� ȣ��� �����Ϸ��� � ��� ��������
	//			�˷� �ִ°�

	p->cry(); // 1. �� ���� p�� Ÿ���� ����
			  // 2. p�� Animal* �Դϴ�.
			  // 3. Animal Ŭ�������� cry �� virtual ��������

	// => virtual �� �ƴϸ� "call Animal::cry" ���� ����
	// => virtual �̸� 
	//  "p�� ����Ű�� �޸𸮰� � Ÿ���� ��ü���� 
	//  "�����ϴ� ���� �ڵ� ����" 
	//  "�� ����� ���� cry() �Լ� ȣ��"
}


