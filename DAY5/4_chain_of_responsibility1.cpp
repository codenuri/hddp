#include <iostream>

// chain of responsibility - 153
// "책임의 전가(고리)"


struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. 자신이 먼저 해결을 시도 - 가상함수 호출
		if (HandleRequest(problem) == true)
			return;	// 문제를 해결했으면 종료

		// 2. 해결이 안되었으면 옆팀이 있다면 전달
		// => 고리(chain)에 따라 책임을 전달
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
			std::cout << "TEAM1 이 해결\n";
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
			std::cout << "TEAM2 이 해결\n";
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
			std::cout << "TEAM3 이 해결\n";
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

//	t1.Handle(7); // 7번 문제 발생.. TEAM1 이 해결

//	t1.Handle(9); // TEAM1 => TEAM2에 전달해서 해결

//	t1.Handle(8); // TEAM1 => TEAM2 => TEAM3 전달해서해결

	t1.Handle(12);

	// 요청하는 객체와 요청을 처리하는 객체의 결합도를 줄여서
	// 요청을 처리할 기회를 여러 객체에 부여
}