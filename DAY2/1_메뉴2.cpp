#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 : 모든 것을 객체로 만들어서 사용.

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		getchar();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command();
}




