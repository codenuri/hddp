#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 방법 2. private 상속

// => 기반 클래스의 구현은 물려받지만(stack 이 내부적으로는 사용)
//    인터페이스를 물려 받지 않겠다(stack 이 list 함수를 노출하지는 않음)
template<typename T>
class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};
int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(10); // error. private 멤버
}