// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

class Dialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// Factory Method : 객체를 만들기 위한 인터페이스를 정의하고사용하지만
	//					객체의 종류는 파생 클래스가 결정
	// template method 와 동일한 구조이지만
	// "알고리즘, 정책"의 변경이 아닌 "객체의 종류"를 결정

	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};




// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

class WinDialog
{
public:

};

class OSXDialog
{
public:
	void init()
	{
		OSXButton* btn = new OSXButton;
		OSXEdit* edit = new OSXEdit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};



int main(int argc, char** argv)
{

}








