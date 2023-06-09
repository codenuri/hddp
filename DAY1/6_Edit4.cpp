// Edit2.cpp
// => template method
// => 변하는 것을 가상함수로
// => 상속 기반의 패턴
// 
// => Edit 가 정책을 포함
// => 다른 컨트롤에서 정책 사용안됨.
// => 실행시간 정책 변경 안됨.

// => Rect::draw_imp() 는 실행시간에 변경될 필요없고,
//    다른 도형에서 재사용할필요도 없다.
//    그림을그리려면 멤버 데이타 접근도 필요
//   => 아래 구현보다는 template method 가 좋다.


// Edit3.cpp
// => strategy
// => 변하는 것을 다른 클래스로
// => 포함기반의 패턴

// => Edit 와 정책의 분리
// => 다른 컨트롤에서 정책 사용가능

// => 실행시간 정책 변경 가능
