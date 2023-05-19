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

	// �ٽ� 1. �Ʒ� �Լ��� static �̾�� �ϴ� ������ �˾ƾ� �մϴ�.
	// C����� callback �Լ��� ��κ� ������ ������ ��ӵǾ� �ֽ��ϴ�
	// callback �� ���Ǵ� ��� �Լ��� static ���� ����Ǿ�� �մϴ�.
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

