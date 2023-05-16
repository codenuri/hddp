#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};


class Dialog
{
public:
	void close() { std::cout << "Dialog close" << std::endl; }
};
void foo() { std::cout << "foo" << std::endl; }


// 일반함수를 실행하는 command
class function_command : public ICommand
{
	using HANDLER = void(*)();
	HANDLER handler;
public:
	function_command(HANDLER h) : handler(h) {}

	void execute() override
	{
		if (handler) 
			handler();
	}
};

template<typename T>
class method_command : public ICommand
{
	using HANDLER = void(T::*)();
	
	T* target = nullptr;
	HANDLER handler = nullptr;
public:
	method_command(HANDLER h, T* t) : handler(h), target(t) {}

	void execute() override
	{
		if (handler && target)
			(target->*handler)(); // 멤버 함수를 호출하는 문법
	}
};


int main()
{
	Dialog dlg;

	ICommand* p1 = new function_command(&foo);
	ICommand* p2 = new method_command<Dialog>(&Dialog::close,
												&dlg);

	p1->execute(); // foo()
	p2->execute(); // dlg.close()
}