#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }

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
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triange" << std::endl; }
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

			// k��° ������ ���纻�� ���� v�� �߰�..
			// �׷���, k��° ������ ����� ?
			// ��� �ڵ带 ������ �ұ�� ?

			/*
			// �Ʒ� �ڵ�� OCP �� �����Ҽ� ����
			// ���� ���� �ڵ� �Դϴ�.
			if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				// v[k] �� Rect�̴� ����.. 
			}
			else if (dynamic_cast<Circle*>(v[k]) != 0)
			{
				// Circle
			}
			*/
		}
	}
}

