#include <iostream>

class Array
{
public:
	int arr[5];

	int size() { return 5; }

	int& operator[](int idx) { return arr[idx]; }
};

int main()
{
	      Array a1 = { 1,2,3,4,5 };
	const Array a2 = { 1,2,3,4,5 };

	// 아래 4줄을 생각해 보세요 - "되야 한다", "안되야 한다"
	//				//원하는것	// 현재상태
	int n1 = a1[0];	//	O			O
	int n2 = a2[0];	//	O			X
	a1[0] = 10;		//	O			O
	a2[0] = 10;		//	X			X

	// 핵심 : 상수객체는 상수 멤버 함수만 호출할수 있다.
}



