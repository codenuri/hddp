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
#include <stack> // 이 안에 있는 stack 이 위 코드와 거의 동일합니다.
				 // 흔히 stack adapter 라고 합니다.
				 // cppreference.com 에서 1번째 화면에서
				 // "Container 라이브러리" 선택
int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::vector<int>> s1;
	stack<int, std::list<int>> s2;
		// => list 를 stack 처럼 사용할수 있게 해달라는 의미
}

