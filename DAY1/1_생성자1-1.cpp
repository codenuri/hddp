//������1.cpp - 3page
#include <iostream>

class Base
{
public:
	// �ٽ� : Base �� ����Ʈ �����ڰ� �����ϴ�.
	Base(int a) { }
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()	{}		// Derived()      : Base() {}
	Derived(int a)	{}	// Derived(int a) : Base() {}

	~Derived() {	}
};
int main()
{
	//	Derived d1;
	Derived d2(5); 

}




