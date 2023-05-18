#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 1. ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// 2. ��� �����̳�(�÷���)������ �ݺ��ڸ� ������ �־�� �Ѵ�.
// �÷����� ��Ģ
template<typename T> struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//------------------------------------------------

// �Ʒ� Ŭ������ ���� "slist" �� �ݺ��� �ڵ�

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

//slist_iterator<int> it(300����);








// slist ���� �ݺ��ڸ� ������ �־�� �մϴ�.
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

// C �ڵ尡 �ڹ� ��Ÿ�� �Դϴ�(�������� ������)

// C++ �������� �����ϴ� �� ����� ����

// 1. next()�� �����Լ� �̴�. ������.

// 2. s.iterator()�� ��ȯ�� �ݺ��ڴ� new�� �������.
//    C++ �̶�� delete �ؾߵ��� ������ ?

// 3. ��� �÷����� ������ ����� �ƴϴ�!!!!
//    raw array �� �����ͷ� �����ϴµ�.. ++�� ����Ѵ�.
//	  int x[5] = {1,2,3,4,5};
//    int* p = x;
//	  ++p; // p->next()�� �ƴ� ++p�� �̵�..