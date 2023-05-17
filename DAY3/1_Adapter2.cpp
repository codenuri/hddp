#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// TextView : 문자열을 보관했다가 이쁘게 출력하는 기능
class TextView
{
	// font 이름, 크기, 두께, 색상
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};
//------------------------------------




class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 어답터의 종류
// 클래스 어답터 : 클래스의 인터페이스 변경
// 객체  어답터  : 객체의 인터페이스 변경

class Text : public TextView, public Shape		
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override { TextView::show(); }
};

// 아래 코드가 "객체 어답터" 입니다.
class ObjectAdapter : public Shape
{
	TextView* view; // 이미 외부에 존재하는 객체를
					// 가리키 겠다는것
					// 이미 존재하는 객체에 기능추가(데코레이터)
					// 이미 존재하는 객체에 인터페이스 변경(어답터)
public:
	ObjectAdapter(TextView* t) : view(t) {}

	// show => draw 로 변경(인터페이스, 즉 함수이름 변경)
	void draw() override 
	{ 
		view->show(); 
	}
};





int main()
{
	std::vector<Shape*> v;

	TextView tv("hello");	// TextView : 클래스
							// tv : 객체

//	v.push_back(&tv); // error


	v.push_back(new ObjectAdapter(&tv)); // ok

	v[0]->draw(); // hello

}







