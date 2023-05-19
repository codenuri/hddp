#include <iostream>

// chain of responsibility - 153
// "å���� ����(��)"


struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. �ڽ��� ���� �ذ��� �õ� - �����Լ� ȣ��
		if (HandleRequest(problem) == true)
			return;	// ������ �ذ������� ����

		// 2. �ذ��� �ȵǾ����� ������ �ִٸ� ����
		// => ��(chain)�� ���� å���� ����
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class TEAM1 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "START TEAM1\n";

		if (problem == 7)
		{
			std::cout << "TEAM1 �� �ذ�\n";
			return true;
		}
		return false;
	}
};

class TEAM2 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "START TEAM2\n";

		if (problem % 2 == 1)
		{
			std::cout << "TEAM2 �� �ذ�\n";
			return true;
		}
		return false;
	}
};
class TEAM3 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "START TEAM3\n";

		if ( problem < 10 )
		{
			std::cout << "TEAM3 �� �ذ�\n";
			return true;
		}
		return false;
	}
};

int main()
{
	TEAM1 t1;
	TEAM2 t2;
	TEAM3 t3;

	t1.next = &t2;
	t2.next = &t3;
	t3.next = nullptr;

//	t1.Handle(7); // 7�� ���� �߻�.. TEAM1 �� �ذ�

//	t1.Handle(9); // TEAM1 => TEAM2�� �����ؼ� �ذ�

//	t1.Handle(8); // TEAM1 => TEAM2 => TEAM3 �����ؼ��ذ�

	t1.Handle(12);

	// ��û�ϴ� ��ü�� ��û�� ó���ϴ� ��ü�� ���յ��� �ٿ���
	// ��û�� ó���� ��ȸ�� ���� ��ü�� �ο�
}