#define USING_GUI
#include "cppmaster.h"




class Window
{
	int handle;
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&MsgProc, title);
	}

	static int MsgProc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: LButtonDown(); break;
		case WM_KEYDOWN:     KeyDown(); break;
		}
		return 0;
	}

	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

// �� �����ΰ��� ? �ذ�å�� ����� ????
// => 4������ �ذ�

int main()
{
	Window w;
	w.Create("A");

	ec_process_message();
}

