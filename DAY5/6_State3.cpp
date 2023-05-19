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

	p = new RedItem;
	p->run();
	p->attack();

}



