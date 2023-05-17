// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture 와 Picture 객체에 기능을 추가하는 객체(DEcorator)
// 는 동일 기반 클래스가 있어어야 한다.(인터페이스)

struct IPicture
{
	virtual void show() = 0;
	virtual ~IPiture() {}
};

class Picture : public IPicture
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


class DrawFrame : public IPicture
{
	IPicture* picture;
public:
	DrawFrame(IPicture* p) : picture(p) {}

	void draw()
	{
		std::cout << "===============" << std::endl;

		picture->draw();

		std::cout << "===============" << std::endl;
	}
};

class DrawFlower : public IPicture
{
	IPicture* picture;
public:
	DrawFlower(IPicture* p) : picture(p) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&" << std::endl;

		picture->draw();

		std::cout << "&&&&&&&&&&&&&&&" << std::endl;
	}
};



int main()
{
	Picture pic("www.image.com/tree.jpg");
	pic.draw();

	DrawFrame frame(&pic); 
	frame.draw(); 

//	DrawFlower flower(&pic);
	DrawFlower flower(&frame);  // 기능의 중첩

	flower.draw();
}


