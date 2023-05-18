#include <iostream>

int main()
{ 
	// 아래 2줄의 차이는 ? 문자열의 실제 위치는 ?
	char sa[] = "abcd";
//	char* sp = "abcd"; // C++ error.

	const char* sp = "abcd"; // ok

	
	const char* p1 = "abcd";
	const char* p2 = "abcd";

	printf("%p\n", p1);
	printf("%p\n", p2);
}