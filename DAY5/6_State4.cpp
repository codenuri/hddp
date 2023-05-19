// 1_State1 - 182 page
#include <iostream>

// 방법 3. 변하는 것을 다른 클래스로!!
// 실행시간 교체되어야 하므로 인터페이스 필요

// 객체의 모든 동작을 인터페이스로 선언
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

	// 객체의 모든 동작을 다른 동작 객체에 위임한다.
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
	// 동작 객체는 데이타가 없고 함수만 있습니다.
	// 싱글톤으로 해도 됩니다.
	EventDay ed;
	NoItem ni;
	SuperItem si;
	Charater* p = new Charater;
	p->set_action(&ni);
	p->run();
	p->attack();

	p->set_action(&ed); // 객체는 변하지 않지만 모든 동작은 변경됩니다.
						// 마치 다른 클래스를 사용하는 것 처럼 보이게됩니다
	p->run();
	p->attack();
}



