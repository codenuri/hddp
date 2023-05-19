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

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유용합니다.
	static Shape* Create() { return new Rect; }
};
// Rect 를 만드는 2가지 방법
// 1. Shape* p1 = new Rect;
// 2. Shape* p2 = Rect::Create();

// 1. 객체를 만들려면 클래스 이름이 필요 합니다!!
// 2. C++은 클래스(이름)을 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); // 이 코드는 클래스를 보관하는 것이 아닌 "문자열 보관"
//							문자열로 객체 생성은 안됩니다.
// 
// 3. 하지만, 객체를 만드는 함수포인터는 보관가능
// v.push_back(&Rect::Create); // 이 정보로는 Rect를 만들수 있습니다.








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)(); // 함수포인터 타입
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
			p = ret->second(); // second 가 map 의 value(함수주소)
		}

		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품을 등록합니다.
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


