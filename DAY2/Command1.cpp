// ����������4.cpp ���� �ϼ���
#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	virtual ~Shape() {}
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triange" << std::endl; }
};

// 1�� ������ => v.push_back(new Rect) ���� ����

// 1�� ������ => command.execute() => v.push_back(newRect) 

// undo �� �����ϰ� �ϴ� ��� ����� �������̽�
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() { v.push_back(new Rect); }
	bool can_undo() { return true; }
	void undo() 
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() { v.push_back(new Circle); }
	bool can_undo() { return true; }
	void undo()
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() 
	{ 
		for (auto p : v)
			p->draw();
	}
	bool can_undo() { return true; }
	void undo() { system("cls");}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;

	ICommand* command = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
//			v.push_back(new Rect); // ���� �������� ����
			command = new AddRectCommand(v); // ��û�� �����ϴ�
			command->execute();				// ��ü�� ����

			cmd_stack.push(command);
		}
		else if (cmd == 2)
		{
			command = new AddCircleCommand(v); 
			command->execute();				
			cmd_stack.push(command);
		}

		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();
			cmd_stack.push(command);
		}
	}
}
