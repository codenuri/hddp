// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// 객체의 생성방법이 아니고... 객체의 공유 이야기
// 
// 속성이 동일한 객체는  공유 할수 있게 하자.
// => 그림을 관리하는 클래스
// => 인터넷에서 다운 받는 기능도 있음

class Image
{
	std::string image_url;
public:
	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void Draw() { std::cout << "Draw " << image_url << std::endl; }
};


int main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->Draw();

}



