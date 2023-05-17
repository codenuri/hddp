// Decorator - 65 page
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Picture : �׸��� Load �ؼ� ȭ�鿡 �׸��� Ŭ����
//           ���ͳݿ��� �׸��� �ٿ� �޴� ��ɵ� ����.
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

// ����� ����� ����� �߰�
// => �׸��� "�׵θ�(����) �� �׸��� ���" �߰�

// Picture pic("tree.png"); 
// => Picture : Ŭ����
// => pic     : ��ü

// 1. ����� ��ü(pic) �� ��� �߰��� �ƴ϶� Ŭ����(Picture)�� ��� �߰�
// 2. ����� ��ø�ɼ� ����.
// => �׸��� "�׵θ��� �׸���", �ٽ� "�� ���� ���� �׸��� �ʹٸ� ??"


class DrawFrame : public Picture
{
public:
	using Picture::Picture; // ������ ���

	void draw()
	{
		std::cout << "===============" << std::endl;

		Picture::draw(); // ���� ��� ���

		std::cout << "===============" << std::endl;
	}
};

class DrawFlower : public Picture
{
public:
	using Picture::Picture; // ������ ���

	void draw()
	{
		std::cout << "&&&&&&&&&&&&&&" << std::endl;

		Picture::draw(); // ���� ��� ���

		std::cout << "&&&&&&&&&&&&&&" << std::endl;
	}
};

int main()
{
	Picture pic("www.image.com/tree.jpg");
	pic.draw();

	DrawFrame frame("www.image.com/tree.jpg");
	frame.draw(); // Picture ��� + �߰��� ��� ���
}


