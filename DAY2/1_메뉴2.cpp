#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� : ��� ���� ��ü�� ���� ���.

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

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command();
}




