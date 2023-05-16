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

// ��� 4. �Լ� �����͸� ����� callback
// => �Ϲ� �Լ� �����Ϳ� ��� �Լ��� ������ ����!!!!
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
	MenuItem m1("�ݱ�", 11);
	MenuItem m2("RED", 21);

//	m1.set_handler(&foo); // �̺�Ʈ ó�� �Լ� ���

	m1.set_handler(&Dialog::close); // ?? ����Լ� ??

	m1.command(); // foo ȣ��
}



