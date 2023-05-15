#include <iostream>
#include <vector>

// �ڵ� ����

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

	// �����Լ� : �Ļ� Ŭ������ ������ ���ص� �ȴ�.
	//			������ ���ϸ� �⺻ ���� ����

	// ���� ���� �Լ� : �Ļ� Ŭ������ �ݵ�� ������ �ؾ� �Ѵ�.

protected:
	virtual void draw_imp() = 0;

public:
//	virtual Shape* clone() = 0;

	// ��ó�� �ص� ������, ���� ���Ǵ� �Լ��� �ƴ϶��
	// �Ʒ� ó�� �ϱ⵵ �մϴ�.
	// => �Ļ� Ŭ������ �ݵ�� ������ �ؾ� �Ǵ� ���� �ƴ�
	// 1. ������ ���ϰ�, ��뵵 ���ϸ� ok
	// 2. ������ ���ϰ�, ����ϸ� ���� �߻�
	// 3. ������ �ϰ�, ����ϸ� ok

	virtual Shape* clone()
	{
		throw not_implementation();
	}
	// get_area() = 0 ���� �ص� �ǰ�..
	// => �����Ǿ� ���� ������ ��Ÿ���� ��ӵ� ��(-1) ��ȯ
	//    �� �ϱ⵵ �Ѵ�.
	// => get_area()�� ����� -1 �̸� ���� ���Ҽ� ������ ���Ѵٰ�
	//    �Ŵ��� �ۼ�
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
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;



			v.push_back(v[k]->clone());
		}
	}
}

