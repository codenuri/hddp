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

	// st ��� ����Ʈ ��ü�� ���� ����
	// ����ϴٰ� ����ó�� �����Ҽ� �־�� ��ü ����� �Դϴ�.
	stack<int> ss(&st); // st �� ����ó��
	ss.pop();	// 3�� ����



	stack<int> s;
	s.push(10);
}

