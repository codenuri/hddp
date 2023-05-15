#include <iostream>
#include <vector>

// 5. ������(�����Լ����)�� OCP �� �����ϴ� ���� �ڵ� �̴�.
// => �����Լ��� �ִ� Ÿ���� "������(polymorphic) Ÿ��" �̶���մϴ�

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
				p->draw(); // ������ (Polymorphism)
					// �ϳ��� ǥ������ ��Ȳ(��ü)�� ����
					// �ٸ��� �����ϴ� ��

			// ��ü ������ 3�� Ư¡ : ���, ĸ��ȭ, ������
		}
	}
}

