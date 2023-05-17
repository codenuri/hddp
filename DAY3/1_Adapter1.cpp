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

// 도형편집기에서 "문자열" 객체도 필요 하다!!
// 예전부터있던, "TextView" 를 사용할수 없을까 ?

// TextView 를 도형편집기에서 사용가능하도록 인터페이스를 변경해 보자
class Text : public TextView,	// TextView 의 모든 기능을물려받고
			 public Shape		// 도형편집기의 요구 조건 
{
public:
	Text(const std::string& data) : TextView(data) {}

	// 인터페이스의 불일치를 해결
	// (show 함수 이름을 draw 로 변경)
	void draw() override { TextView::show(); }
};

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw();
}







