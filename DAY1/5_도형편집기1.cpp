#include <iostream>
#include <vector>

// �Ŀ� ����Ʈ ���� ���α׷��� ����� ���� ������ ���ô�.

// �ٽ� 1. �� ������ Ÿ������ �����ϸ� ���ϴ�.
// 
// �ٽ� 2. ��� ������ ��� Ŭ������ �ִٸ� ��� ������
//        �ϳ��� �����̳ʿ� ��� �����Ҽ� �ִ�.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w,h �� �����ڵ��� ����..
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v1; // Rect ��ü�� ���� ����
//	std::vector<Circle*> v2;

	std::vector<Shape*> v; // ��� ������ �ϳ��� �����̳ʿ�
							// ��� ����!!
}

