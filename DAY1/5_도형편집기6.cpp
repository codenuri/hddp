#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }



	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� ���� ���ϴ� ����
	//    �и��Ǿ�� �մϴ�.
	// => ���ϴ� ���� �����Լ��� �и��ϼ���

	virtual void draw_imp()
	{
		std::cout << "draw shape" << std::endl; 
	}
	virtual void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}




	virtual ~Shape() {}


	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = this->color; 

		return s;

	}
};



class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }

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
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;



			v.push_back(v[k]->clone()); 
		}
	}
}

