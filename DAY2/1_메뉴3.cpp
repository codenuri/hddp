#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


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

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}
	
	void add_menu(MenuItem* m) { v.push_back(m); }

	// 핵심 : 팝업메뉴를 선택시 해야할일을 생각해 보세요
	void command()
	{
		int sz = v.size();

		int idx = 0;	
		for (auto m : v)
		{
			std::cout << ++id << ". " << m->get_title() << "\n";
		}

		std::cout << sz + 1 << ". 종료\n";

		std::cout << "메뉴를 선택하세요 >> ";
		int cmd;
		std::cin >> cmd;

		// 선택된 메뉴 실행
		v[cmd - 1]->command();
	}

};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 메뉴");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// 팝업메뉴를 선택시 해야할일을 생각해보세요
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >>
}




