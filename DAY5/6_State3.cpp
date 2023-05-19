// 1_State1 - 182 page
#include <iostream>

// 방법 2. 변하는 것을 가상함수로

class Charater
{
	int gold;
	int item;
public:
	void run() { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

// 상속을 통한 동작의  변경
class RedItem : public Character
{
public:
	void do_run() override { std::cout << "fast run" << std::endl; }
	void do_attack() override { std::cout << "power attack" << std::endl; }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItem; // 동작뿐 아니라 상태(데이타)도 바뀐것
				     // 즉, 새로운 객체를 만든것
					 // 우리가 원하는 것은 동일 객체의 동작을 교체
	p->run();
	p->attack();

}



