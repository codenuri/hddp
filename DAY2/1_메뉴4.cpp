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
};




class MenuItem
{

	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}



	void command()
	{
		std::cout << get_title() << " ¸Þ´º ¼±ÅÃµÊ" << std::endl;

		getchar();
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

			std::cout << sz + 1 << ". Á¾·á\n";

			std::cout << "¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä >> ";
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
	MenuItem m1("¼Ò°í±â±è¹ä", 11);
	MenuItem m2("ÂüÄ¡ ±è¹ä", 12);

	PopupMenu kimbab("±è¹äÁ¾·ù");
	kimbab.add_menu(&m1);
	kimbab.add_menu(&m2);

	MenuItem m3("¶ó¸é", 21);

	PopupMenu pm("¿À´ÃÀÇ ¸Þ´º");

	pm.add_menu(&kimbab); // ÇÙ½É.. ÆË¾÷ÀÌ ´Ù½Ã ÆË¾÷º¸°ü
	pm.add_menu(&m3);

	pm.command();	
}




