#include <iostream>
#include <vector>

// 핵심 3. 모든 도형(파생 클래스)의 공통의 특징은
//		  반드시 기반 클래스에 있어야 한다.(문법이 아닌 디자인 규칙)
//	      그래야, Shape* 로 묶었을때 해당 기능을 사용할수 있다.

class Shape
{
public:
	void draw() { std::cout << "draw shape" << std::endl; }

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

