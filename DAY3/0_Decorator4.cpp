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

// Picture ��ü�� ����� �߰��ϴ�
// ��� �߰� ��ü(Decorator)��
// ������ Ư¡�� �ֽ��ϴ�.
// ��� Ŭ������ �����մϴ�.

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

	DrawFlower flower(&frame);  // ����� ��ø
	flower.draw();
}




// Decorator �� Composite ������
// Class Diagram �� ���� �����մϴ�.

// ����� ���� : A�� B�� ���������� A�ڽŵ� ����
//             => A�� B�� ������ ��� Ŭ���� �ʿ�...

// �׷���.. ��?? ���ҷ��� ����� ������ �ϴµ�....�ǵ��� ����..!!
// ���հ�ü(������ü�� ����) �Ϸ��� ����� ���� ��� : composite
// ������ ���� ��ü�� ����� �߰��Ϸ��� �ǵ� : decorator


