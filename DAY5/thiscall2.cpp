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


	// �Ʒ� ������ ��� �Լ� ������ �Դϴ�.
	void(Dialog::*f4)(int) = &Dialog::Close; // ok

	// �Ʒ� ó���ϸ� �ȵǳ��� ??? => �ȵ˴ϴ�. �� ó�� �ؾ� �մϴ�.
	void(*f4)(Dialog*, int) = &Dialog::Close;


	p1.set(10, 20); // set(&p1, 10, 20) ���� �̾߱� �ϴµ�..
					// ���� ���ڿ� ��ü�� ���޵Ǵ� �����
					// �����Ϸ��� ���� �ٸ��ϴ�.
					// push	20
					// push	10
					// mov ecx, &p1		// this
					// call Point::set
}
/*
class AAA
{
public:
	void f1(int a, int b) {}

	// explicit object parameter - C++23, 
	// deducing this ����
	// ���̽� ó�� ����Լ� 1��° ���ڷ� self �� �޴� ���.
	void f2(this T& self, int a, int b) {}
};
class BB : AAA
{
}
BBB aaa;
aaa.f1(1, 2);
aaa.f2(1, 2);
*/

