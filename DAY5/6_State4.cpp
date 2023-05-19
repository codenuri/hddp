// 1_State1 - 182 page
#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ������!!
// ����ð� ��ü�Ǿ�� �ϹǷ� �������̽� �ʿ�

// ��ü�� ��� ������ �������̽��� ����
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// jump(), slide(), .... 
};

class Charater
{
	int gold;
	int item;
	IAction* action = nullptr;
public:
	void set_action(IAction* a) { action = a; }

	// ��ü�� ��� ������ �ٸ� ���� ��ü�� �����Ѵ�.
	void run() { action->run(); }
	void attack() { action->attack(); }
};

class NoItem : public IAction
{
public:
	void run() { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};
class SuperItem : public IAction
{
public:
	void run() { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power attack" << std::endl; }
};
class EventDay : public IAction
{
public:
	void run() { std::cout << "fast fast run" << std::endl; }
	void attack() { std::cout << "supre power attack" << std::endl; }
};

int main()
{
	// ���� ��ü�� ����Ÿ�� ���� �Լ��� �ֽ��ϴ�.
	// �̱������� �ص� �˴ϴ�.
	EventDay ed;
	NoItem ni;
	SuperItem si;
	Charater* p = new Charater;
	p->set_action(&ni);
	p->run();
	p->attack();

	p->set_action(&ed); // ��ü�� ������ ������ ��� ������ ����˴ϴ�.
						// ��ġ �ٸ� Ŭ������ ����ϴ� �� ó�� ���̰Ե˴ϴ�
	p->run();
	p->attack();
}



