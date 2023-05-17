#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. STL 에는 linked list 가 있다.
// 2. 그런데, 사용자가 stack 을 요구 한다. 

// list 의 함수 이름을 stack 처럼 보이도록 변경하는 어답터
template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back(); }
};


int main()
{
	stack<int> s;
	s.push(10);
}