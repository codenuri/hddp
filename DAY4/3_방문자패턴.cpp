#include <iostream>
#include <list>
#include <vector>




// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 방법 1. 직접 모든 요소를 열거
	for (auto& e : s)
		e *= 2;

	// 방법 2. 방문자 패턴 사용
	TwiceVisitor<int> tv; // 모든 요소를 2배로 하는 방문자
	s.accept(&tv);		  // 복합객체에 방문자 넣기!!

	ShowVisitor<int> sv;  // 모든 요소를 출력하는 방문자
	s.accept(&sv);

}





