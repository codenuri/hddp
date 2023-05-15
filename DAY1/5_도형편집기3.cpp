#include <iostream>
#include <vector>

// �ٽ� 3. ��� ����(�Ļ� Ŭ����)�� ������ Ư¡��
//		  �ݵ�� ��� Ŭ������ �־�� �Ѵ�.(������ �ƴ� ������ ��Ģ)
//	      �׷���, Shape* �� �������� �ش� ����� ����Ҽ� �ִ�.

// �ٽ� 4. ��� Ŭ������ ���� ��� �Լ���. �Ļ� Ŭ������ override
//        �ϰԵǴ� ���� �ݵ�� �����Լ��� �ؾ� �Ѵ�.

class Shape
{
	int color;
public:

	// �Ʒ� �Լ��� �������� �ұ�� ? ��������� ?
	// => �Ʒ� �Լ��� �Ļ� Ŭ������ ������ �� ���� �����ϴ�.
	// => non-virtual
	void set_color(int c) { color = c; }

	// => ��� ������ ���� ���ϴ� ����� �ٸ��ϴ�.
	// => virtual �̾�� �մϴ�.
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

