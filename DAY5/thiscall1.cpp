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
	// static ��� �Լ��� this �߰� �ȵʴϴ�.
	static void foo(int n) // void foo(int n)
	{
//		x = n;		// this->x = n �� �Ǿ�� �ϴµ�
	}				//             foo �ȿ��� this�� ��� error.
};
int main()
{
	Point::foo(10);

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) �� ����
	p2.set(10, 20); // set(&p2, 10, 20)
}



