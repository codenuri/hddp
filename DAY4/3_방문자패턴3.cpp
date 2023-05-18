#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list      : ��� ��Ұ� ������ Ÿ���� ������ ���հ�ü
// PopupMenu : ��� ��Ұ� ��� ���� Ÿ���� �ƴϴ�.
//             ���հ�ü�ȿ� �ٽ� ���հ�ü�� �������� �ִ�

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu* m) = 0;
	virtual void visit(MenuItem* m) = 0;

	virtual ~IMenuVisitor() {}
};

// ��� �޴��� �湮�ڸ� ����ؾ� �Ѵ�.
struct IAcceptor
{
	virtual void accept(IMenuVisitor* visitor) = 0;
	virtual ~IAcceptor() {}
};




class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s)
	{
		title = s;
	}


	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void accept(IMenuVisitor* visitor) override
	{
		// �޴� �������� ���հ�ü�� �ƴϹǷ� �ڽŸ� �湮�ڿ� ����
		visitor->visit(this);
	}


	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}


	// �湮�ڰ� �˾��޴��� �湮�Ҷ�
	void accept(IMenuVisitor* visitor)
	{
		// �湮�ڿ� �ڽ��� ����
		visitor->visit(this);

		// ���� �޴��� ����
		// => �Ʒ� ó���ϸ� ���� �ڽ� �޴� ������ ���޵˴ϴ�.
		//for (auto e : v)
		//	visitor->visit(e);

		// �ذ� : ���� �޴��� �ٽ� �湮�ڸ� �湮
		for (auto e : v)
			e->accept(visitor);
	}







	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". ����" << std::endl;

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};

class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void visit(MenuItem* m) override {}
	void visit(PopupMenu* m) override 
	{
		auto s = "[ " + m->get_title() + " ]";

		m->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	PopupMenuTitleChangeVisitor pmv;
	root->accept(&pmv); // root �� ��� �޴��� �湮�ؼ�
						// �˾��϶��� Ÿ��Ʋ�� �����ϴ� 
						// �湮��

	// ���� 1. �湮�ڸ� �ݵ�� root �� �־�߸� �ϴ� ���� �ƴմϴ�.
	//        �Ѱ� ��ü���� �־ �˴ϴ�.

	MenuItem* m = new MenuItem("8K", 14);
	
	pm1->accept(m);

	m->accept(&pmv); // �̷��� �ص� �˴ϴ�.


	root->command();

}




