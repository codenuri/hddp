#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}


	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;

		getchar();
		getchar();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // 핵심
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* m) { v.push_back(m); }



	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			int idx = 0;

			for (auto m : v)
			{
				std::cout << ++idx << ". " << m->get_title() << "\n";
			}

			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}

	}
};


int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);
//	pm1->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));
	pm1->add_menu(new MenuItem("8K", 14));

	pm2->add_menu(new MenuItem("RED",   21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// 이제 메뉴를 시작 하려면 ?
	// 각 메뉴 객체의 포함관계를 그림으로 생각해 보세요.. 
	root->command();
}

// 객체지향 언어에서 프로그램이란 ?

// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 과정이다.(서로 멤버함수를 호출하는 것)

// 객체지향 프로그램에서 모든 것은 "객체"이다.


