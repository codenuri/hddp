#define USING_GUI
#include "cppmaster.h"

#include <map>

class Window;

std::map<int, Window*> this_map;

// 클래스 템플릿 만들때
// T를 사용하지 않은 모든 멤버 함수는
// 템플릿이 아닌 기반 클래스를 만들어서 제공해라
// => "thin template" 기술

class Window
{
protected:
	int handle;
public:
	// 수백개의 윈도우 관련 함수들..
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

