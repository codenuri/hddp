#include <iostream>
#include <vector>

// 5. 다형성(가상함수기반)은 OCP 를 만족하는 좋은 코드 이다.
// => 가상함수가 있는 타입을 "다형적(polymorphic) 타입" 이라고합니다

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
				p->draw(); // 다형성 (Polymorphism)
					// 하나의 표현식이 상황(객체)에 따라
					// 다르게 동작하는 것

			// 객체 지향의 3대 특징 : 상속, 캡슐화, 다형성
		}
	}
}

