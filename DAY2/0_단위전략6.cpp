#include <iostream>
#include <vector>
#include <allocators> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	int* p1 = new int[10];
	delete[] p1;

	// 2. allocator ���
	std::allocator<int> ax; // �޸� �Ҵ��

	int* p = ax.allocate(10);	// ǥ���Ҵ��� �޸��Ҵ�

	ax.deallocate(p, 10); 

}