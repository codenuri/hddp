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
	std::vector<BaseMenu*> v; // �ٽ�
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

			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";
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

// ��� 5. command ����
// => C#�� WPF, QT�� undo manager ��� ���Ǵ� ���
// => ������ ����ε�,, ���� �ٽ� ���� ���

// ����� �������̽�.. ��� ����� �����Ҽ� �ִ�.
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

// Dialog �� �ݴ� ��� ��ü
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
	MenuItem m1("�ݱ�", 11);
	MenuItem m2("RED", 21);

	// �޴� ���ý� �ؾ� ������ ���� ��ɰ�ü ����
	m1.set_command(new DialogCloseCommand(&dlg) );

	m1.command();
}



