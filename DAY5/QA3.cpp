#include <iostream>

class Array
{
public:
	int arr[5];

	int size() { return 5; }

	// C++ 에서 멤버 함수 만들때 동일 이름을
	// "const 멤버와 non-const 멤버" 로 만들때가 (아주)많습니다.
	      int& operator[](int idx){ return arr[idx]; }
	const int& operator[](int idx) const { return arr[idx]; }
};

int main()
{
	Array a1 = { 1,2,3,4,5 };
	const Array a2 = { 1,2,3,4,5 };

	// 아래 4줄을 생각해 보세요 - "되야 한다", "안되야 한다"
	//				//원하는것	// 현재상태
	int n1 = a1[0];	//	O			O
	int n2 = a2[0];	//	O			O
	a1[0] = 10;		//	O			O
	a2[0] = 10;		//	X			X

	// 핵심 : 상수객체는 상수 멤버 함수만 호출할수 있다.
}



