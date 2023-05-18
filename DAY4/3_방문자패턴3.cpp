#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list      : 모든 요소가 동일한 타입을 가지는 복합객체
// PopupMenu : 모든 요소가 모두 동일 타입이 아니다.
//             복합객체안에 다시 복합객체가 있을수도 있다

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu* m) = 0;
	virtual void visit(MenuItem* m) = 0;

	virtual ~IMenuVisitor() {}
};

// 모든 메뉴는 방문자를 허락해야 한다.
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
		// 메뉴 아이템은 복합객체가 아니므로 자신만 방문자에 전달
		visitor->visit(this);
	}


	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}


	// 방문자가 팝업메뉴를 방문할때
	void accept(IMenuVisitor* visitor)
	{
		// 방문자에 자신을 전달
		visitor->visit(this);

		// 하위 메뉴도 전달
		// => 아래 처럼하면 직계 자식 메뉴 까지만 전달됩니다.
		//for (auto e : v)
		//	visitor->visit(e);

		// 해결 : 하위 메뉴에 다시 방문자를 방문
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

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
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
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	PopupMenuTitleChangeVisitor pmv;
	root->accept(&pmv); // root 의 모든 메뉴를 방문해서
						// 팝업일때만 타이틀을 변경하는 
						// 방문자

	// 참고 1. 방문자를 반드시 root 에 넣어야만 하는 것은 아닙니다.
	//        한개 객체에만 넣어도 됩니다.

	MenuItem* m = new MenuItem("8K", 14);
	
	pm1->accept(m);

	m->accept(&pmv); // 이렇게 해도 됩니다.


	root->command();

}




