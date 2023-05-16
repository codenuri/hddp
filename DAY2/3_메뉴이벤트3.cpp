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
// ��� 2. ���ϴ� ���� �����Լ���
// => MenuItem �� �Ļ� Ŭ���� ������ �ʹ� ��������!!
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
	using MenuItem::MenuItem; // ������ ��� ����
								// ��� Ŭ������ �����ڸ� ����ش޶�.
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
	DialogCloseMenu m1("�ݱ�", 11);

	RedMenu m2("RED", 21);

	m1.command();
}



