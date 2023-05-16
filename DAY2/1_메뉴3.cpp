#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�\n";
		getchar();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}
	
	void add_menu(MenuItem* m) { v.push_back(m); }

	// �ٽ� : �˾��޴��� ���ý� �ؾ������� ������ ������
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

			if (cmd == sz + 1)  // ���� �޴� ���� 
				break;

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue ;


			// ���õ� �޴� ����
			v[cmd - 1]->command();
		}

	}



};


int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ �޴�");

	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// �˾��޴��� ���ý� �ؾ������� �����غ�����
					// 1. ���
					// 2. ���
					// 3. ����
					// �޴��� �����ϼ��� >>
}




