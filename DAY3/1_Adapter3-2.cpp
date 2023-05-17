#include <iostream>
#include <list>
#include <vector>
#include <deque>

// private 상속 : 기반 클래스의 가상함수를 재정의할 기회가 있습니다
// 포함         : 상속이 아니므로 가상함수 재정의는 안됨.


// 방법 3. 상속이 아닌 포함
// => 항상 상속보다 포함을 먼저 고려해라!!

// => stack 은 list의 모든 기능이 아닌 일부 기능만 필요
template<typename T>
class stack
{
	std::list<T> c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()		      { return c.back(); }
};
int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(10); // error. 이런이름의 함수는 없음.
}