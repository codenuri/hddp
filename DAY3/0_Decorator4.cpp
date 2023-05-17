// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;


struct IPicture
{
	virtual void draw() = 0;
	virtual ~IPicture() {}
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

// Picture 객체에 기능을 추가하는
// 기능 추가 객체(Decorator)는
// 공통의 특징이 있습니다.
// 기반 클래스로 제공합니다.

class IDecorator : public IPicture
{
	IPicture* picture;
public:
	IDecorator(IPicture* p) : picture(p) {}

	void draw() { picture->draw(); } 
};


class DrawFrame : public IDecorator
{
public:
	DrawFrame(IPicture* p) : IDecorator(p) {}

	void draw()
	{
		std::cout << "===============" << std::endl;

		IDecorator::draw();

		std::cout << "===============" << std::endl;
	}
};

class DrawFlower : public IDecorator
{
public:
	DrawFlower(IPicture* p) : IDecorator(p) {}

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&&" << std::endl;

		IDecorator::draw();

		std::cout << "&&&&&&&&&&&&&&&" << std::endl;
	}
};



int main()
{
	Picture pic("www.image.com/tree.jpg");
	pic.draw();

	DrawFrame frame(&pic);
	frame.draw();

	DrawFlower flower(&frame);  // 기능의 중첩
	flower.draw();
}


