#include <iostream>
#include <vector>

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
				p->draw(); 
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;

			// k번째 도형의 복사본을 만들어서 v에 추가..
			// 그런데, k번째 도형이 뭘까요 ?
			// 어떻게 코드를 만들어야 할까요 ?

			/*
			// 아래 코드는 OCP 를 만족할수 없는
			// 좋지 않은 코드 입니다.
			if (dynamic_cast<Rect*>(v[k]) != 0)
			{
				// v[k] 는 Rect이다 복사.. 
			}
			else if (dynamic_cast<Circle*>(v[k]) != 0)
			{
				// Circle
			}
			*/
		}
	}
}

