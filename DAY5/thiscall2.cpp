#include <functional> 

class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};
void foo(int a) {} 

int main()
{
	void(*f1)(int) = &foo;	// ok				
	void(*f2)(int) = &Dialog::Close; // error
								// Close �� this�� �߰��Ǵ� �Լ�

	void(*f3)(int) = &Dialog::Close2; // ok

	// �ٽ� 
	// 1. �Ϲ� �Լ������Ϳ���        ��� �Լ��� �ּҸ� ������ �����ϴ�.
	// 2. �Ϲ� �Լ������Ϳ��� static ��� �Լ��� �ּҸ� ������ �ֽ��ϴ�.
}






