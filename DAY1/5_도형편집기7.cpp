#include <iostream>
#include <vector>

// 코드 정리

class not_implementation {};

class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }

public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}

	// 가상함수 : 파생 클래스가 재정의 안해도 된다.
	//			재정의 안하면 기본 구현 제공

	// 순수 가상 함수 : 파생 클래스는 반드시 재정의 해야 한다.

protected:
	virtual void draw_imp() = 0;

public:
//	virtual Shape* clone() = 0;

	// 위처럼 해도 되지만, 자주 사용되는 함수가 아니라면
	// 아래 처럼 하기도 합니다.
	// => 파생 클래스는 반드시 재정의 해야 되는 것은 아님
	// 1. 재정의 안하고, 사용도 안하면 ok
	// 2. 재정의 안하고, 사용하면 예외 발생
	// 3. 재정의 하고, 사용하면 ok

	virtual Shape* clone()
	{
		throw not_implementation();
	}
	// get_area() = 0 으로 해도 되고..
	// => 구현되어 있지 않음을 나타내는 약속된 값(-1) 반환
	//    을 하기도 한다.
	// => get_area()의 결과가 -1 이면 면적 구할수 없음을 뜻한다고
	//    매뉴얼 작성
	virtual int get_area() { return -1; }

	virtual ~Shape() {}



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

