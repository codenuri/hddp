#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};


// �Ʒ� Ŭ������ ���� "slist" �� �ݺ��� �ڵ�

template<typename T>
class slist_iterator 
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	// ++�� �������� �̵��� �Ѵ�.
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }

	// ==, != �� ����
	inline bool operator==(const slist_iterator& it)
	{
		return current == it.current;
	}
	inline bool operator!=(const slist_iterator& it)
	{
		return current != it.current;
	}
};
// slist_iterator<int> p(300����)
// ++p; �̵�
// int n = *p; // ������
// p1 == p2; // �񱳵� ����


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);
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
	
}

