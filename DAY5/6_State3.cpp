// 1_State1 - 182 page
#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���

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

// ����� ���� ������  ����
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



