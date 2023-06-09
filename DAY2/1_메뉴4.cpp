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
		std::cout << get_title() << " �޴� ���õ�" << std::endl;

		getchar();
		getchar();
	}
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
};


int main()
{
	MenuItem m1("�Ұ�����", 11);
	MenuItem m2("��ġ ���", 12);

	PopupMenu kimbab("�������");
	kimbab.add_menu(&m1);
	kimbab.add_menu(&m2);

	MenuItem m3("���", 21);

	PopupMenu pm("������ �޴�");

	pm.add_menu(&kimbab); // �ٽ�.. �˾��� �ٽ� �˾�����
	pm.add_menu(&m3);

	pm.command();	
}




