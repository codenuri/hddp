#include <iostream>
#include <vector>

// 핵심 9. template method 패턴
// => 기반 클래스에 전체적인 흐름을 담은 메소드 제공
// => 변하는 것만 가상함수화 해서 파생 클래스가 재정의할수
//    있는 기회 제공

// => 가정 널리 사용되는 패턴

class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }



	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 숨은 변하는 것을
	//    분리되어야 합니다.
	// => 변하는 것을 가상함수로 분리하세요

protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape" << std::endl; 
	}
public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}




	virtual ~Shape() {}


	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = this->color; 

		return s;

	}
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
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;



			v.push_back(v[k]->clone()); 
		}
	}
}

