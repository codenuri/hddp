#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 1. 모든 반복자가 지켜야 하는 규칙
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// 2. 모든 컨테이너(컬렉션)에서는 반복자를 꺼낼수 있어야 한다.
// 컬렉션의 규칙
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//------------------------------------------------

// 아래 클래스가 실제 "slist" 의 반복자 코드

template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	T& next() override
	{
		T& ret = current->data;
		current = current->next;
		return ret;
	}

	bool hasNext() override { return current != nullptr; }
};

//slist_iterator<int> it(300번지);








// slist 에서 반복자를 꺼낼수 있어야 합니다.
template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto p = s.iterator();

	while (p->hasNext())
	{
		std::cout << p->next() << ", ";
	}
	// 40, 30, 20, 10
}

// C 코드가 자바 스타일 입니다(전통적인 디자인)

// C++ 진영에서 생각하는 위 방식의 단점

// 1. next()가 가상함수 이다. 느리다.

// 2. s.iterator()가 반환한 반복자는 new로 만들었다.
//    C++ 이라면 delete 해야되지 않을까 ?

// 3. 모든 컬렉션이 동일한 방법이 아니다!!!!
//    raw array 는 포인터로 열거하는데.. ++을 사용한다.
//	  int x[5] = {1,2,3,4,5};
//    int* p = x;
//	  ++p; // p->next()가 아닌 ++p로 이동..