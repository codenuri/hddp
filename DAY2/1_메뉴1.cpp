// 2_메뉴1.cpp  - 55 page
#include <iostream>


// C언어로 만든 메뉴
// 장점 : 쉽고, 빠르다.
// 단점 : 요구사항이 증가하면 코드가 복잡해진다.
//	     => 새로운 메뉴가 추가되면 여러곳 수정
//		 => 하위메뉴가 있다면..
int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


