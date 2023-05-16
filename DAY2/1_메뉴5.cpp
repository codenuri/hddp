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
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);
//	pm1->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));
	pm1->add_menu(new MenuItem("8K", 14));

	pm2->add_menu(new MenuItem("RED",   21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	// ���� �޴��� ���� �Ϸ��� ?
	// �� �޴� ��ü�� ���԰��踦 �׸����� ������ ������.. 
	root->command();
}

// ��ü���� ���� ���α׷��̶� ?

// 1. ��ü�� �����ϰ�
// 2. ��ü���� ���踦 �����ϰ�
// 3. ��ü���� �޼����� �ְ� �޴� �����̴�.(���� ����Լ��� ȣ���ϴ� ��)

// ��ü���� ���α׷����� ��� ���� "��ü"�̴�.


