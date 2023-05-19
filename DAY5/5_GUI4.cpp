#define USING_GUI
#include "cppmaster.h"

#include <map>

class Window;

// this 를 자료구조에 보관했다 사용하는 기술 - 아주 유명한 기술입니다.
std::map<int, Window*> this_map;



class Window
{
	int handle;
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&MsgProc, title);

		// "윈도우 번호 - 객체" 를 자료구조에 보관
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

int main()
{
	MainWindow w;
	w.Create("A");

	ec_process_message();
}

