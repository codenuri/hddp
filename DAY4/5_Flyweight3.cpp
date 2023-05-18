
#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

// Image 객체를 만들어서 관리하는 별도의 클래스
class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto p = image_map.find(url);

		if (p == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = p->second;
		return img;
	}
};




int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



