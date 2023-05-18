// 방문자 패턴의 의미!!
class Shape
{
	virtual void Draw() = 0;
};
class Rect   : public Shape {};
class Circle : public Shape {};


// 전통적인 객체지향 디자인
// => ? 자리에 "쉽다"  "어렵다" 로 채워 보세요.
// 클래스의   추가 :  
// 가상함수의 추가 : 



// 그런데, Move()라는 가상함수를 추가하지말고!!
ShapeMoveVisitor v;
컨테이너.accept(&v); // 이렇게 하면 ??


// 방문자 패턴으로 디자인 하면
// 클래스의 추가   : 
// 가상 함수의 추가 :



