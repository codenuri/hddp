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


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();
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
			p = ret->second();
		}

		return p;
	}
};

// �Ʒ� Ŭ���� ��Ȱ�� �� ������ ������
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

//AutoRegister ar(1, &Rect::Create);




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static ��� ����Ÿ�� �����ڴ� main �Լ� ���� ���� ȣ��˴ϴ�.
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// new Rect;  => Rect ������ ȣ��
//				��, �����ڴ� ��ü�� ���鶧 ���� ȣ��
// ���� ar�� �����ڴ� "Rect" �� ������ �ʾƵ� ���ʿ� �ѹ� ȣ��
// ��, ��ü�� �ƴ� Ŭ������ ���ؼ� ���ʿ� �ѹ� ȣ��
// => C# ����� static ������ ����

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();
	
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);


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


