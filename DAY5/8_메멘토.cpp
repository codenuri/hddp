// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// ��� 1. �Լ� ���ڷ� ��������.
	// Windows�� gdi+ ���̺귯��
	g.DrawLine(0, 0, 100, 100, red, 10);


	// ��� 2. Graphics �� �Ӽ����� ��������.
	// IOS �� ��� - cocoa touch
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100); //��ǥ�� ����
}









