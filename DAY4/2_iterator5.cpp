#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


// 아래 클래스가 실제 "slist" 의 반복자 코드

template<typename T>
class slist_iterator 
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	// ++은 다음으로 이동만 한다.
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }

	// ==, != 가 지원
	inline bool operator==(const slist_iterator& it)
	{
		return current == it.current;
	}
	inline bool operator!=(const slist_iterator& it)
	{
		return current != it.current;
	}
};
// slist_iterator<int> p(300번지)
// ++p; 이동
// int n = *p; // 꺼내기
// p1 == p2; // 비교도 가능


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
	}
	slist_iterator<T> end()
	{
		return slist_iterator<T>(0);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto p = s.begin();
	++p; // 
	std::cout << *p << std::endl; // 30
	

	auto first = s.begin();
	auto last = s.end();

	while (first != last)
//	while( first != std::default_sentinel) // C++20
	{
		std::cout << *first << ", ";
		++first;
	}
}
// visual studio 2022 preivew 17.7 부터 많이 지원 - std::print()
/*
Point* foo()
{
	Point pt;
	return &pt; // 버그. 이렇게 안되고
	return new Point; // Point* 로 반환한다면 이렇게 해야만 합니다.
}
Point foo()
{
	Point pt;
	return pt; // ok!!
	return Point(); // 위와 같은 의미.
}
Point ret = foo(); // ok
*/