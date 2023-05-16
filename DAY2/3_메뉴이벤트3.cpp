#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 



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
//----------------------------------------------

class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};
// 방법 2. 변하는 것을 가상함수로
// => MenuItem 의 파생 클래스 갯수가 너무 많아진다!!
class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		do_command();
	}
	virtual void do_command() {}
};
//-----------------
class DialogCloseMenu : public MenuItem
{
public:
	using MenuItem::MenuItem; // 생성자 상속 문법
								// 기반 클래스의 생성자를 상속해달라.
	void do_command()
	{
		std::cout << "Dialog Close" << std::endl;
	}
};
class RedMenu : public MenuItem
{
public:
	using MenuItem::MenuItem; 
	void do_command()
	{
		std::cout << "Red" << std::endl;
	}
};
int main()
{
	DialogCloseMenu m1("닫기", 11);

	RedMenu m2("RED", 21);

	m1.command();
}



