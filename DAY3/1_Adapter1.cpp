#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// TextView : ���ڿ��� �����ߴٰ� �̻ڰ� ����ϴ� ���
class TextView
{
	// font �̸�, ũ��, �β�, ����
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};
//------------------------------------




class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// ���������⿡�� "���ڿ�" ��ü�� �ʿ� �ϴ�!!
// ���������ִ�, "TextView" �� ����Ҽ� ������ ?

// TextView �� ���������⿡�� ��밡���ϵ��� �������̽��� ������ ����
class Text : public TextView,	// TextView �� ��� ����������ް�
			 public Shape		// ������������ �䱸 ���� 
{
public:
	Text(const std::string& data) : TextView(data) {}

	// �������̽��� ����ġ�� �ذ�
	// (show �Լ� �̸��� draw �� ����)
	void draw() override { TextView::show(); }
};

int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw();
}







