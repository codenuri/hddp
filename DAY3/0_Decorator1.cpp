// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture : 그림을 Load 해서 화면에 그리는 클래스
//           인터넷에서 그림을 다운 받는 기능도 있음.
class Picture
{
	std::string url;
public:
	Picture(const std::string& url) : url(url)
	{
		std::cout << "start downding..." << std::endl;
		std::this_thread::sleep_for(3s);
		std::cout << "end downding..." << std::endl;
	}
	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

// 상속을 사용한 기능의 추가
// => 그림에 "테두리(액자) 를 그리는 기능" 추가

// Picture pic("tree.png"); 
// => Picture : 클래스
// => pic     : 객체

// 1. 상속은 객체(pic) 에 기능 추가가 아니라 클래스(Picture)의 기능 추가
// 2. 기능이 중첩될수 없다.
// => 그림에 "테두리를 그리고", 다시 "그 위에 꽃을 그리고 싶다면 ??"


class DrawFrame : public Picture
{
public:
	using Picture::Picture; // 생성자 상속

	void draw()
	{
		std::cout << "===============" << std::endl;

		Picture::draw(); // 기존 기능 사용

		std::cout << "===============" << std::endl;
	}
};

class DrawFlower : public Picture
{
public:
	using Picture::Picture; // 생성자 상속

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&" << std::endl;

		Picture::draw(); // 기존 기능 사용

		std::cout << "&&&&&&&&&&&&&&" << std::endl;
	}
};

int main()
{
	Picture pic("www.image.com/tree.jpg");
	pic.draw();

	DrawFrame frame("www.image.com/tree.jpg");
	frame.draw(); // Picture 기능 + 추가된 기능 사용
}


