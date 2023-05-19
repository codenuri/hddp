// 5번,   2번복사하세요


#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* Create() { return new Rect; }

	Shape* Clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
	Shape* Clone() override { return new Circle(*this); }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void Register(int key, Shape* prototype)
	{
		prototype_map[key] = prototype;
	}


	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);

		if (ret != prototype_map.end())
		{
			p = ret->second->Clone();
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품을 등록합니다.
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// 공장에 클래스가 아닌 객체를 등록해 봅시다.
	Rect* redRect = new Rect; 
	Rect* blueRect = new Rect;
	Circle* redCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);




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


