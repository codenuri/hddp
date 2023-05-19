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

	// 핵심 1. 아래 함수가 static 이어야 하는 이유를 알아야 합니다.
	// C언어의 callback 함수는 대부분 인자의 갯수가 약속되어 있습니다
	// callback 로 사용되는 멤버 함수는 static 으로 설계되어야 합니다.
	static int MsgProc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create("A");

	ec_process_message();
}

