#include <iostream>
#include <String>
#include <vector>
#include <map>
#include <string>

// 문자의 font 관련 속성은 대부분 동일한 경우가 많습니다.
class Font
{
	std::string font_name;
	int color;
	int size;
public:
};

// 동일 속성의 폰트를 공유하는 공장
class FontFlyweightFactory
{
	std::map<std::string, Font*> font_map;
public:
	Font* create(std::string key)
	{
		//......
	}
};

class Character
{
	char ch;
	Font* font;
public:
	Character(char c) : ch(c)
	{
		FontFlyweightFactory& ff = FontFlyweightFactory::getInstance();

		font = ff.create("굴림_12_black");
	}
};

int main()
{
	Character* c1 = new Character('A');
	Character* c2 = new Character('B');

}