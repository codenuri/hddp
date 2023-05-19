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
		// 1. 자신이 먼저 해결을 시도 - 가상함수 호출
		if (LButtonDown() == true)
			return;	// 문제를 해결했으면 종료

		// 2. 해결이 안되었으면 parent 윈도우에 전달
	
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
	//	return true;	// 메세지 처리를 종료
		return false;   // 메세지를 부모 윈도우에 보내 달라.
	}
};
// 위 기술을 IOS 에서는 "responder chain" 이라고 하고
// C# WPF 에서는 "bubbling event" 라고 합니다.
// C++ MFC 에서는 "command routing" 이라고 합니다.

int main()
{
	MainWindow w;
	w.Create("A");

	ImageView imgview;
	imgview.Create("imgview");

	w.AddChild(&imgview);

	ec_process_message();
}

