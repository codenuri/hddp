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

struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};

class function_command : public ICommand
{
	using HANDLER = void(*)();
	HANDLER handler;
public:
	function_command(HANDLER h) : handler(h) {}

	void execute() override
	{
		if (handler)
			handler();
	}
};

template<typename T>
class method_command : public ICommand
{
	using HANDLER = void(T::*)();

	T* target = nullptr;
	HANDLER handler = nullptr;
public:
	method_command(HANDLER h, T* t) : handler(h), target(t) {}

	void execute() override
	{
		if (handler && target)
			(target->*handler)(); // 멤버 함수를 호출하는 문법
	}
};

template<typename T>
method_command<T>* cmd(void(T::* method)(), T* target)
{
	return new method_command<T>(method, target);
}

function_command* cmd(void(*f)())
{
	return new function_command(f);
}




class MenuItem : public BaseMenu
{
	int id;
	ICommand* cmd = nullptr;
public:
	void set_command(ICommand* p) { cmd = p; }

	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	void command()
	{
		if (cmd)
			cmd->execute();
	}
};








int main()
{
	Dialog dlg;
	MenuItem m1("닫기", 11);
	MenuItem m2("RED", 21);

//	m1.set_command(new DialogCloseCommand(&dlg));

	m1.set_command(cmd(&Dialog::close, &dlg));
//	m2.set_command(cmd(&foo));
	
	m1.command();
}

// 참고
void foo()
{
	void(*f1)() = &foo;
	void(Dialog::*f2)() = &Dialog::close;

	f1(); // ok
//	f2(); // error. 객체 필요

	Dialog dlg;
	(dlg.*f2)(); // ok.. pointer to member 라는 연산자
				//     .* 연산자
}