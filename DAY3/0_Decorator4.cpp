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




// Decorator 와 Composite 패턴은
// Class Diagram 이 거의 동일합니다.

// 재귀적 포함 : A는 B를 포함하지만 A자신도 포함
//             => A와 B는 공통의 기반 클래스 필요...

// 그런데.. 왜?? 뭐할려고 재귀적 포함을 하는데....의도가 뭔데..!!
// 복합객체(여러객체를 보관) 하려고 재귀적 포함 사용 : composite
// 기존에 만든 객체에 기능을 추가하려는 의도 : decorator


