#include <iostream>

class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{						
		x = a;			   //	this->x = a;			
		y = b;				
	}	
	// static 멤버 함수는 this 추가 안됨니다.
	static void foo(int n) // void foo(int n)
	{
//		x = n;		// this->x = n 이 되어야 하는데
	}				//             foo 안에는 this가 없어서 error.
};
int main()
{
	Point::foo(10);

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) 로 변경
	p2.set(10, 20); // set(&p2, 10, 20)
}



