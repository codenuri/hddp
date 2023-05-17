// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture �� Picture ��ü�� ����� �߰��ϴ� ��ü(DEcorator)
// �� ���� ��� Ŭ������ �־��� �Ѵ�.(�������̽�)

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
	DrawFlower flower(&frame);  // ����� ��ø

	flower.draw();
}


