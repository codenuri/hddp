#define USING_GUI
#include "cppmaster.h"

#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;



class Window
{
	int handle;

	Window* parent = nullptr; // �θ� ������� �Ѱ�!!!
	std::vector<Window*> v;   // �ڽ� ������� ������
public:
	void AddChild(Window* child)
	{
		child->parent = this;
		v.push_back(child);

		// C�Լ��� �ڽ�������� ����
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
		case WM_LBUTTONDOWN: self->LButtonDown(); break;
		case WM_KEYDOWN:     self->KeyDown(); break;
		}
		return 0;
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};
//----------------------------------
class MainWindow : public Window
{
public:
	void LButtonDown()
	{
		std::cout << "MainWindow LBUTTON\n";
	}
};

class ImageView : public Window
{
public:
	void LButtonDown()
	{
		std::cout << "ImageView LBUTTON\n";
	}
};
int main()
{
	MainWindow w;
	w.Create("A");

	ImageView imgview;
	imgview.Create("imgview");

	w.AddChild(&imgview);

	ec_process_message();
}

