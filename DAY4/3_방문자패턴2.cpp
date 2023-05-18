#include <iostream>
#include <list>
#include <vector>

// 1. 방문자 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 2. 방문의 대상의 인터페이스
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

// 실제 방문자들
// => 핵심 : 한개 요소에 대한 연산을 정의하는 클래스!!
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { std::cout << e << ", "; }
};

// STL list 에 accept 추가
template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // 생성자 상속
					// MyList 를 std::list 와 완전히 동일한
					// 방식으로 생성 가능하게 할수 있다

	void accept(IVisitor<T>* visitor) override
	{
		// 자신의 모든 요소를 방문자에게 전달합니다.
		for (auto& e : *this) // <== *this는 결국 list
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);		  

	ShowVisitor<int> sv;  
	s.accept(&sv);

}





