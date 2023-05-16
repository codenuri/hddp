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

// 방법 5. command 패턴
// => C#의 WPF, QT의 undo manager 등에서 사용되는 기술
// => 오래된 기술인데,, 요즘에 다시 많이 사용

// 명령의 인터페이스.. 모든 명령은 실행할수 있다.
struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};



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

// Dialog 를 닫는 명령 객체
class DialogCloseCommand : public ICommand
{
	Dialog* dlg;
public:
	DialogCloseCommand(Dialog* d) : dlg(d) {}

	void execute() override { dlg->close(); }
};

int main()
{
	Dialog dlg;
	MenuItem m1("닫기", 11);
	MenuItem m2("RED", 21);

	// 메뉴 선택시 해야 할일을 담은 명령객체 전달
	m1.set_command(new DialogCloseCommand(&dlg) );

	m1.command();
}



