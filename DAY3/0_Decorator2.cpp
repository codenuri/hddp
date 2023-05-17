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

// ����(������ �Ǵ� ���� ���)�� ����� ����� �߰�
// => Ŭ������ �ƴ� ��ü�� ��� �߰�!

class DrawFrame 
{
	Picture* picture; // �ٽ� : ����� �ƴ� ������ �Ǵ� 
						//      ���� ����� �߰�!!
						// �ܺο� �̹� ������� �ִ� ��ü��
						// ����Ű�ڴٴ� �ǵ�.
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

	DrawFrame frame(&pic); // pic ��ü�� �׵θ��� �׸��� ����߰�
	frame.draw(); // pic �׸� �׸��� ��� + �׵θ� �׸��� ����߰�
}


