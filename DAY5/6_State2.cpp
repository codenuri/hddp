#include <iostream>

// 방법 1. 상태에 따라 제어문 사용
// => 모든 동작(멤버 함수)에 제어문 필요
// => 새로운 아이템이 나오면 제어문 추가
class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if (item == 1)
			std::cout << "run" << std::endl;	

		else if (item == 2)
			std::cout << "fast run" << std::endl;
	}
	void attack() { std::cout << "attack" << std::endl; }
};


int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



