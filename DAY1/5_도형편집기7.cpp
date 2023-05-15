#include <iostream>
#include <vector>

// 코드 정리

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
	virtual void draw_imp()
	{
		std::cout << "draw shape" << std::endl;
	}
public:
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = this->color;

		return s;
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

