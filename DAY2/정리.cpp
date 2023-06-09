// 정리

// 디자인 패턴 : 객체지향 프로그램 작성에 사용되는 디자인 기술
//			   대부분의 객체지향 언어의 공통의 기술
//			   특정 언어의 고유한 기술이 적용되어 있지 않음

// IDioms : 각 언어의 특징을 고려한 디자인 기술
// C++IDioms, java Idioms

// 구글에서 "C++ IDioms" 검색해 보세요.  1번째 링크

// 디자인 패턴의 핵심 1.
// => 클래스 내부의 변하는 코드를 분리하자는 것

// 1. 변하는 것을 가상함수로 : template method,, draw()/draw_imp()
// 
// 2. 변하는 것을 클래스로
//		=> 변하는 것을 담은 클래스(정책, 알고리즘)을 어떻게 교체할것인가 ?
//      A. 인터페이스를 설계해서 교체 - strategy, Edit/IValidator
//								=> 느리지만(가상함수), 실행시간 교체 가능

//		B. 템플릿 인자로 교체 - policy base design(단위전략)
//							 C++ IDioms, STL 이 아주 널리 사용하는 기술