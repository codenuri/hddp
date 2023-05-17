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
#include <stack> // �� �ȿ� �ִ� stack �� �� �ڵ�� ���� �����մϴ�.
				 // ���� stack adapter ��� �մϴ�.
				 // cppreference.com ���� 1��° ȭ�鿡��
				 // "Container ���̺귯��" ����
int main()
{
	stack<int> s;
	s.push(10);

	stack<int, std::vector<int>> s1;
	stack<int, std::list<int>> s2;
		// => list �� stack ó�� ����Ҽ� �ְ� �ش޶�� �ǹ�
}

