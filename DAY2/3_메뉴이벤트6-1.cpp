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


// �Ϲ��Լ��� �����ϴ� command
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
			(target->*handler)(); // ��� �Լ��� ȣ���ϴ� ����
	}
};

// ��ü�� ����� ����� �����ϴٸ�
// ��ü�� ����� �Լ��� �����ض�
template<typename T>
method_command<T>* cmd(void(T::* method)(), T* target)
{
	return new method_command<T>(method, target);
}

function_command* cmd(void(*f)())
{
	return new function_command(f);
}



int main()
{
	Dialog dlg;

	// �ǹ� : �Ϲ��Լ� �ּҿ� ��� �Լ��� �ּҸ� ���� Ÿ�Կ� �����ߴٰ�����
	// (ICommand* Ÿ��)
//	ICommand* p1 = new function_command(&foo);
//	ICommand* p2 = new method_command<Dialog>(&Dialog::close,
//												&dlg);
	ICommand* p1 = cmd(&foo);
	ICommand* p2 = cmd(&Dialog::close, &dlg);

	p1->execute(); // foo()
	p2->execute(); // dlg.close()
}