#define USING_GUI
#include "cppmaster.h"

#include <map>

class Window;

std::map<int, Window*> this_map;

// Ŭ���� ���ø� ���鶧
// T�� ������� ���� ��� ��� �Լ���
// ���ø��� �ƴ� ��� Ŭ������ ���� �����ض�
// => "thin template" ���

class Window
{
protected:
	int handle;
public:
	// ���鰳�� ������ ���� �Լ���..
	void MoveWindow() {} 

	void LButtonDown() {}
	void KeyDown() {}
};

template<typename T> 
class MsgWindow : public Window
{
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&MsgProc, title);
		this_map[handle] = this;
	}
	static int MsgProc(int hwnd, int msg, int a, int b)
	{
//		Window* self = this_map[hwnd];

		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->LButtonDown(); break;
		case WM_KEYDOWN:     self->KeyDown(); break;
		}
		return 0;
	}
};
//----------------------------------
class MainWindow : public MsgWindow<MainWindow>
{
public:
	void LButtonDown()
	{
		std::cout << "MainWindow LBUTTON\n";
	}
};

int main()
{
	MainWindow w;
	w.Create("A");

	ec_process_message();
}

