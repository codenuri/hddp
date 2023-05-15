#include <iostream>
#include <vector>

// �ٽ� 6. �����������̶� ?
// => 1994�� 4���� ���ڰ� ���� å�� �̸�
// 
// => GOF's Design Pattern : Gangs Of four

// => ���� ���Ǵ� �ڵ� ��Ÿ�Ͽ� �̸��� �ο� �Ѵ�.
// => 23���� �̸�

// �ٽ� 7. prototype ���� : �ߺ���ü�� �����
//						���縦 ���ؼ� ��ü�� �����ϴ°�
//						clone()�����Լ�
//						����ϳ� ���� ��Ȯ�� ����.

// �ٽ� 8. �Ʒ� �����丵 ��� ������ ������
// 
// => "Replace Conditional With Polymorphism"
//              (���)��        (�����Լ���)


class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	virtual ~Shape() {}


	// �ڽ��� ���纻�� ����� �ִ� �����Լ��� 
	// ���� �����ϰ� ���˴ϴ�.
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = this->color; // ��� ����� ���� �����ϰԼ���

		return s;

//		return new Shape(*this); // �Ǵ� ���� �����ڷ� ����
	}
};



class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw rect" << std::endl; }

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

			// k ��° ���纻�� ���� v�� �߰��ϱ�
			v.push_back( v[k]->clone() ); // ������
							// k��° ������ � �������� 
							// �� �ʿ����.
		}
	}
}

