#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop() { c.pop_back(); }
	inline T& top() { return c.back(); }
};

int main()
{
	std::list<int> st = { 1,2,3 };

	// st 라는 리스트 객체를 먼저 만들어서
	// 사용하다가 스택처럼 변경할수 있어야 객체 어답터 입니다.
	stack<int> ss(&st); // st 를 스택처럼
						// 이렇게 하려면 STACK 안에 
						// list* 또는 list& 가 멤버로 있어야합니다
						// 위코드는 list 이므로 객체 어답터 가아닌
						// 클래스 어답터 입니다.
	ss.pop();	// 3을 제거



	stack<int> s;
	s.push(10);
}

