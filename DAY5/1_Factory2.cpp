#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// �ڽ��� ��ü�� ����� static ��� �Լ��� ���� �����մϴ�.
	static Shape* Create() { return new Rect; }
};
// Rect �� ����� 2���� ���
// 1. Shape* p1 = new Rect;
// 2. Shape* p2 = Rect::Create();

// 1. ��ü�� ������� Ŭ���� �̸��� �ʿ� �մϴ�!!
// 2. C++�� Ŭ����(�̸�)�� �ڷᱸ���� �����Ҽ� �����ϴ�.
// v.push_back("Rect"); // �� �ڵ�� Ŭ������ �����ϴ� ���� �ƴ� "���ڿ� ����"
//							���ڿ��� ��ü ������ �ȵ˴ϴ�.
// 
// 3. ������, ��ü�� ����� �Լ������ʹ� ��������
// v.push_back(&Rect::Create); // �� �����δ� Rect�� ����� �ֽ��ϴ�.








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)(); // �Լ������� Ÿ��
	std::map<int, CREATOR> create_map;

public:
	void Register(int key, CREATOR f)
	{
		create_map[key] = f;
	}
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		
		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); // second �� map �� value(�Լ��ּ�)
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// ���忡 ��ǰ�� ����մϴ�.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) 
		{
			Shape* s = factory.Create(cmd);

			if (s)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}


