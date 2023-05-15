#include <iostream>
#include <vector>

class Shape
{
public:
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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw(); // error
						// p는 Shape* 인데
						// Shape 에는 draw 없다
		}
	}
}
// 왜? 위 코드가 에러 일까요 ?
// 해결책은 뭘까요 ?
// 1. Shape* 인 p를 Rect* 또는 Circle* 캐스팅
// 2. Shape 안에도 draw()를 만들자.

