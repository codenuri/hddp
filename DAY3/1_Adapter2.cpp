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

// ������� ����
// Ŭ���� ����� : Ŭ������ �������̽� ����
// ��ü  �����  : ��ü�� �������̽� ����

class Text : public TextView, public Shape		
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override { TextView::show(); }
};

// �Ʒ� �ڵ尡 "��ü �����" �Դϴ�.
class ObjectAdapter : public Shape
{
	TextView* view; // �̹� �ܺο� �����ϴ� ��ü��
					// ����Ű �ڴٴ°�
					// �̹� �����ϴ� ��ü�� ����߰�(���ڷ�����)
					// �̹� �����ϴ� ��ü�� �������̽� ����(�����)
public:
	ObjectAdapter(TextView* t) : view(t) {}

	// show => draw �� ����(�������̽�, �� �Լ��̸� ����)
	void draw() override 
	{ 
		view->show(); 
	}
};





int main()
{
	std::vector<Shape*> v;

	TextView tv("hello");	// TextView : Ŭ����
							// tv : ��ü

//	v.push_back(&tv); // error


	v.push_back(new ObjectAdapter(&tv)); // ok

	v[0]->draw(); // hello

}







