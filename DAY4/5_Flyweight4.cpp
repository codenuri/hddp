#include <iostream>
#include <String>
#include <vector>

class Character
{
	char ch;

	// MSWORD 에서 대부분의 문자는 아래 데이타는 공유 하게 됩니다.
	// 그런데 아래 처럼 설계하면 공유되지 않습니다.
	std::string font_name;
	int color;
	int size;
public:
};

int main()
{
	std::vector<Character> v[10];
}