#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ��� 3. ����� �ƴ� ����
// => �׻� ��Ӻ��� ������ ���� ����ض�!!

// => stack �� list�� ��� ����� �ƴ� �Ϻ� ��ɸ� �ʿ�
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

	s.push_front(10); // error. �̷��̸��� �Լ��� ����.
}