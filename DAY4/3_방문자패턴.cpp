#include <iostream>
#include <list>
#include <vector>




// visitor ����
// 
// �ݺ���(iterator) : ���հ�ü�� ��� ��Ҹ� ������ ������� ����
// �湮��(visitor)  : ���հ�ü�� ��� ��Ҹ� ������ ������� �������


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s�� ��� ��Ҹ� 2��� �ϰ� �ʹ�.

	// ��� 1. ���� ��� ��Ҹ� ����
	for (auto& e : s)
		e *= 2;

	// ��� 2. �湮�� ���� ���
	TwiceVisitor<int> tv; // ��� ��Ҹ� 2��� �ϴ� �湮��
	s.accept(&tv);		  // ���հ�ü�� �湮�� �ֱ�!!

	ShowVisitor<int> sv;  // ��� ��Ҹ� ����ϴ� �湮��
	s.accept(&sv);

}





