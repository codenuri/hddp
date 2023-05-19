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

class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};



#define REGISTER(classname)								\
	static Shape* Create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_IMPL(key, classname)	\
	AutoRegister Rect::ar(key, &classname::Create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(Rect)
};
REGISTER_IMPL(1, Rect)




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(Circle)
};
REGISTER_IMPL(2, Circle)

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(Triangle)
};
REGISTER_IMPL(3, Triangle)


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

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


