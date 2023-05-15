#include <iostream>

class Base
{
public:
	virtual ~Base() {} // ��� Ŭ������ �ݵ�� �Ҹ��ڸ�						// �����Լ��� �ؾ� �մϴ�.
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	 ~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	// ������ ȣ��
//	delete p;					// �Ҹ��� ȣ��

	// �ٽ� : �Ʒ� �ڵ� ��� Ȯ���� ������
	Base* p = new Derived;
	delete p;	// 1. �Ҹ��� ȣ��
				// 2. �޸� ����
	// �Ҹ��� ȣ�⵵ "�ᱹ �Լ� ȣ��" �Դϴ�
	// 
	// 1. �Ҹ��ڰ� �������� �����ؾ� �մϴ�.
	//    => p �� Base* �̹Ƿ� Base Ŭ������ ����

	// �Ҹ��ڰ� ������ �ƴϸ� : ~Base() ��ȣ��
	// �Ҹ��ڰ� �����̸�     : p�� ����Ű�� ��ü�� Ÿ���� ������
	//						ȣ��

}	
