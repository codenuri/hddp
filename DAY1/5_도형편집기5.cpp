#include <iostream>
#include <vector>

// 핵심 6. 디자인패턴이란 ?
// => 1994년 4명의 저자가 만든 책의 이름
// 
// => GOF's Design Pattern : Gangs Of four

// => 자주 사용되는 코딩 스타일에 이름을 부여 한다.
// => 23개의 이름

// 핵심 7. prototype 패턴 : 견본객체를 만들고
//						복사를 통해서 객체를 생성하는것
//						clone()가상함수
//						목요일날 보다 정확히 수업.

// 핵심 8. 아래 리팩토링 용어 이해해 보세요
// 
// => "Replace Conditional With Polymorphism"
//              (제어문)을        (가상함수로)


class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	virtual ~Shape() {}


	// 자신의 복사본을 만들수 있는 가상함수는 
	// 아주 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		Shape* s = new Shape;
		s->color = this->color; // 모든 멤버를 나와 동일하게설정

		return s;

//		return new Shape(*this); // 또는 복사 생성자로 생성
	}
};



class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }

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

			// k 번째 복사본을 만들어서 v에 추가하기
			v.push_back( v[k]->clone() ); // 다형성
							// k번째 도형이 어떤 도형인지 
							// 알 필요없다.
		}
	}
}

