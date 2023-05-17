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

// 포함(포인터 또는 참조 멤버)을 사용한 기능의 추가
// => 클래스가 아닌 객체에 기능 추가!

class DrawFrame 
{
	Picture* picture; // 핵심 : 상속이 아닌 포인터 또는 
						//      참조 멤버로 추가!!
						// 외부에 이미 만들어져 있는 객체를
						// 가리키겠다는 의도.
public:
	DrawFrame(Picture* p) : picture(p) {}

	void draw()
	{
		std::cout << "===============" << std::endl;

		picture->draw();

		std::cout << "===============" << std::endl;
	}
};




int main()
{
	Picture pic("www.image.com/tree.jpg");
	pic.draw();

	DrawFrame frame(&pic); // pic 객체에 테두리를 그리는 기능추가
	frame.draw(); // pic 그림 그리기 기능 + 테두리 그리는 기능추가
}


