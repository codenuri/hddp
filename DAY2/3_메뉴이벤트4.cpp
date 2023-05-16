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


// 방법 3. 변하는 것을 다른 클래스로
// => listener 방식
// => java, 안드로이드가 사용하는 방식

// 메뉴 이벤트를 처리하고 싶은 클래스는 반드시 아래 인터페이스를 구현해라.!
struct IMenuListener
{
	virtual void on_command(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int id;
	IMenuListener* listener = nullptr;
public:
	void set_listener(IMenuListener* p) { listener = p; }

	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		if (listener)
			listener->on_command( id );
	}
};

// 메뉴 이벤트를 처리하고 싶은 클래스는 반드시 
// IMenuListener 를 구현해야 한다.
class Dialog : public IMenuListener
{
public:
	void on_command(int id) override
	{
		switch (id)
		{
		case 11: close(); break;
		case 12: break;
		}
		
	}
	void close() { std::cout << "Dialog close" << std::endl; }
};
int main()
{
	Dialog dlg;
	MenuItem m1("닫기", 11);
	MenuItem m2("RED", 21);

	m1.set_listener(&dlg);
	m2.set_listener(&dlg);


	m1.command();
}



