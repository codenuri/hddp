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

// 방법 4. 함수 포인터를 사용한 callback
// => 일반 함수 포인터에 멤버 함수를 담을수 없다!!!!
class MenuItem : public BaseMenu
{
	int id;
	using HANDLER = void(*)(); // typedef void(*HANDLER)()

	HANDLER handler = nullptr;
public:
	void set_handler(HANDLER h) { handler = h; }

	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		if (handler)
			handler();
	}
};
void foo() { std::cout << "foo" << std::endl; }

int main()
{
	MenuItem m1("닫기", 11);
	MenuItem m2("RED", 21);

//	m1.set_handler(&foo); // 이벤트 처리 함수 등록

	m1.set_handler(&Dialog::close); // ?? 멤버함수 ??

	m1.command(); // foo 호출
}



