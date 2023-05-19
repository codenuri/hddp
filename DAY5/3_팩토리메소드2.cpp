// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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
	// Factory Method : ��ü�� ����� ���� �������̽��� �����ϰ���������
	//					��ü�� ������ �Ļ� Ŭ������ ����
	// template method �� ������ ����������
	// "�˰���, ��å"�� ������ �ƴ� "��ü�� ����"�� ����

	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};

// Style �ɼǰ� ������� �׻� Windows ����� Dialog

class WinDialog : public Dialog
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit* CreateEdit() { return new WinEdit; }
};

class OSXDialog : public Dialog
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit* CreateEdit() { return new OSXEdit; }
};



int main(int argc, char** argv)
{

}








