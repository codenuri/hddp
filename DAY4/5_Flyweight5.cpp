#include <iostream>

int main()
{ 
	// �Ʒ� 2���� ���̴� ? ���ڿ��� ���� ��ġ�� ?
	char sa[] = "abcd";
//	char* sp = "abcd"; // C++ error.

	const char* sp = "abcd"; // ok

	
	const char* p1 = "abcd";
	const char* p2 = "abcd";

	printf("%p\n", p1);
	printf("%p\n", p2);
}