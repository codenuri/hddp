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

// 아래 클래스 역활을 잘 생각해 보세요
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

	// static 멤버 데이타의 생성자는 main 함수 보다 먼저 호출됩니다.
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// new Rect;  => Rect 생성자 호출
//				즉, 생성자는 객체를 만들때 마다 호출
// 위의 ar의 생성자는 "Rect" 를 만들지 않아도 최초에 한번 호출
// 즉, 객체가 아닌 클래스에 대해서 최초에 한번 호출
// => C# 언어의 static 생성자 개념

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


