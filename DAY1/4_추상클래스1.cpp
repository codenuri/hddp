// 1_추상클래스1.cpp - 10page


// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다. 포인터 변수는 만들수 있다.
// 의도 : 특정 멤버 함수를 반드시 만들라고, 지시하는 것
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
							 // => 구현부가 없고, =0으로 표기
							 
};
class Rect : public Shape
{
	// Draw() 함수의 구현을 제공하지 않으면 역시 추상 클래스
	// Rect 객체를 만들수 있게 하려면 "Draw()" 구현제공해야 한다.
public:
	void Draw() override {}
};
int main()
{
	Shape  s; // error
	Shape* p; // ok.
	Rect  r;
}
