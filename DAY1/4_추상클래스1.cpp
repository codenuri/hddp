// 1_�߻�Ŭ����1.cpp - 10page


// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)
							 // => �����ΰ� ����, =0���� ǥ��
							 
};


class Rect : public Shape
{
};
int main()
{
	Shape  s; 
	Shape* p; 
	Rect  r;
}
