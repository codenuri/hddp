#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*
// 아래 처럼 만들면 "type safe" 한 모델 입니다.
// root->get_submenu(0)->add_menu(...) 처럼 사용할수 없습니다
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};
*/
// 아래 처럼 하면 "복합객체와 개별객체의 사용법을 동일시" 하는 모양입니다.
// root->get_submenu(0)->add_menu(...) 사용가능

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}
	std::string get_title() { return title; }
	virtual void command() = 0;

	virtual void add_menu(BaseMenu*) { throw unsupported_operation(); }
	virtual BaseMenu* get_submenu(int idx) { throw unsupported_operation(); }
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
	BaseMenu* get_submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("root");
		
	root->add_menu(new PopupMenu("색상변경"));
	root->add_menu(new MenuItem("붙여넣기", 11));

	// get_submenu()를 만들어 봅시다.
//	BaseMenu* m = root->get_submenu(0);
//	m->add_menu(new MenuItem("RED", 11)); // ??


	root->get_submenu(0)->add_menu(new MenuItem("RED",11)); // ok
	// root[0]->add_menu()
	// root[0][1][2];

	try
	{
		root->get_submenu(1)->add_menu(new MenuItem("RED", 11));
		// 예외 발생
	}
	catch (...)
	{
		std::cout << "예외 발생" << std::endl;
	}

	root->command();
}



