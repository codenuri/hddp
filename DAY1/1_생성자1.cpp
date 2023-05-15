//������1.cpp - 3page
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
	// ����� �ڵ�		// �����Ϸ��� �����Ѱ�
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

		// ~Base();  // �Ҹ��ڴ� Derived ������ ���� �����Ŀ�
					 // Base �Ҹ��� ȣ��
	}
};
int main()
{
//	Derived d1;
	Derived d2(5); // call Derived::Derived(int) ȣ��

}







// DAY1.zip ���� Ǯ�� ������
// DAY1.sln ���� ����Ŭ���ؼ� ���ø� �˴ϴ�.

// 1. ���� �����ؾ� �մϴ�.
//    => ������Ʈ �޴�, �Ӽ� �޴� ����
// 
// 2. Ctrl + F5 �� ���� �Ǵ��� Ȯ���� ������
// 3. �ҽ��� ���忡 ����/���� �ϴ� ���

// ����
// 1. C++ ���� ����
// 2. ���ǿ��� �ٷ�� �پ��� ������
// 3. ���������� 23�� ����!