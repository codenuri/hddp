#include <iostream>
#include <vector>


class not_implementation {};

class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }

public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}
protected:
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone()
	{
		throw not_implementation();
	}

	virtual int get_area() { return -1; }

	virtual ~Shape() {}



};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle" << std::endl; }

	Shape* clone() override
	{
		return new Circle(*this);
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해볼 문제 1. 객체의 생성을 OCP를 만족하게 할수 없을까?
		// => 추상팩토리 패턴을 알면 됩니다.(목요일날)

		// 2. Undo/Redo 를 넣으려면 어떻게 해야 할까 ?
		// => Command 패턴을 적용하면 됩니다.(목요일날)

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
		}
	}
}

