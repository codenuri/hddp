// 1_추상클래스1.cpp - 10page


// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
							 // => 구현부가 없고, =0으로 표기
							 
};


class Rect : public Shape
{
};
int main()
{
	Shape  s; 
	Shape* p; 
	Rect  r;
}
