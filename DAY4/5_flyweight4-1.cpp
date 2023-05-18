#include <iostream>
#include <String>
#include <vector>
#include <map>
#include <string>

// ������ font ���� �Ӽ��� ��κ� ������ ��찡 �����ϴ�.
class Font
{
	std::string font_name;
	int color;
	int size;
public:
};

// ���� �Ӽ��� ��Ʈ�� �����ϴ� ����
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

		font = ff.create("����_12_black");
	}
};

int main()
{
	Character* c1 = new Character('A');
	Character* c2 = new Character('B');

}