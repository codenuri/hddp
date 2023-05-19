#define USING_GUI
#include "cppmaster.h"

#include <map>
#include <vector>

class Window
{
	static std::map<int, Window*> this_map;

	int handle;

	Window* parent = nullptr; 
	std::vector<Window*> v;   
public:
	void AddChild(Window* child)
	{
		child->parent = this;
		v.push_back(child);

		ec_add_child(this->handle, child->handle);
	}




	void Create(const char* title)
	{
		handle = ec_make_window(&MsgProc, title);
		this_map[handle] = this;
	}

	static int MsgProc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->Handle(); break;
		case WM_KEYDOWN:     self->KeyDown(); break;
		}
		return 0;
	}

	void Handle()
	{
		// 1. �ڽ��� ���� �ذ��� �õ� - �����Լ� ȣ��
		if (LButtonDown() == true)
			return;	// ������ �ذ������� ����

		// 2. �ذ��� �ȵǾ����� parent �����쿡 ����
	
		if (parent != 0)
			parent->Handle();
	}

	virtual bool LButtonDown() { return false; }
	virtual bool KeyDown() { return false; }
};

std::map<int, Window*> Window::this_map;


//----------------------------------
class MainWindow : public Window
{
public:
	bool LButtonDown()
	{
		std::cout << "MainWindow LBUTTON\n";
		return true;
	}
};

class ImageView : public Window
{
public:
	bool LButtonDown()
	{
		std::cout << "ImageView LBUTTON\n";
	//	return true;	// �޼��� ó���� ����
		return false;   // �޼����� �θ� �����쿡 ���� �޶�.
	}
};
// �� ����� IOS ������ "responder chain" �̶�� �ϰ�
// C# WPF ������ "bubbling event" ��� �մϴ�.
// C++ MFC ������ "command routing" �̶�� �մϴ�.

int main()
{
	MainWindow w;
	w.Create("A");

	ImageView imgview;
	imgview.Create("imgview");

	w.AddChild(&imgview);

	ec_process_message();
}

