#include <iostream>
#include <vector>

// 핵심 3. 모든 도형(파생 클래스)의 공통의 특징은
//		  반드시 기반 클래스에 있어야 한다.(문법이 아닌 디자인 규칙)
//	      그래야, Shape* 로 묶었을때 해당 기능을 사용할수 있다.

// 핵심 4. 기반 클래스가 가진 멤버 함수중. 파생 클래스가 override
//        하게되는 것은 반드시 가상함수로 해야 한다.

class Shape
{
	int color;
public:

	// 아래 함수는 가상으로 할까요 ? 하지말까요 ?
	// => 아래 함수를 파생 클래스가 재정의 할 이유 없습니다.
	// => non-virtual
	void set_color(int c) { color = c; }

	// => 모든 도형은 면적 구하는 방법이 다릅니다.
	// => virtual 이어야 합니다.
	virtual int get_area() { return -1;}

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	virtual ~Shape() {}
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
	}
}

