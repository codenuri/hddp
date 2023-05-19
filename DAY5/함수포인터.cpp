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
	// 1. ��� �Լ� �ּ� ���
	void(Dialog::*f4)(int) = &Dialog::Close; 

	// 2. ��� �Լ� �����ͷ� �Լ� ȣ���ϱ� - �ٽ�!!
	f4(10); // error. ��ü�� ����.

	Dialog dlg;
//	dlg.f4(10); // error. dlg �ȿ� f4��� ��� �����ϴ�.

	// .* ������ "pointer to member operator" ��� ������
	//			 C++ ���� ������
	//dlg.*f4(10); // error. ������ �켱������ .* ���� ( ������.

	(dlg.*f4)(10); // ok.. ��� �Լ� �����ͷ� ��� �Լ��� 
					// ȣ���ϴ� �ڵ�.
	
	// �Ϲ� �Լ� ������ ���� : f1(10)
	// ��� �Լ� ������ ���� : (dlg.*f4)(10)

	// ��� ȣ�� ������ ��ü�� �ϰ����ְ� �������
	std::invoke(f1, 10); // f1(10)
	std::invoke(f4, &dlg, 10); // (dlg.*f4)(10)

	// => C++17 �̰�  <functional>
}

// �����Ͻôٸ� ������ smkang @ codenuri.co.kr

