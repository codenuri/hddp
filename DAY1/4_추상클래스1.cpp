// 1_�߻�Ŭ����1.cpp - 10page


// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡ : ��ü�� ����� ����. ������ ������ ����� �ִ�.
// �ǵ� : Ư�� ��� �Լ��� �ݵ�� ������, �����ϴ� ��
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)
							 // => �����ΰ� ����, =0���� ǥ��
							 
};
class Rect : public Shape
{
	// Draw() �Լ��� ������ �������� ������ ���� �߻� Ŭ����
	// Rect ��ü�� ����� �ְ� �Ϸ��� "Draw()" ���������ؾ� �Ѵ�.
public:
	void Draw() override {}
};
int main()
{
	Shape  s; // error
	Shape* p; // ok.
	Rect  r;
}
