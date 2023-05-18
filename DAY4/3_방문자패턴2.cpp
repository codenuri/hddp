#include <iostream>
#include <list>
#include <vector>

// 1. �湮�� �������̽�
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 2. �湮�� ����� �������̽�
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

// ���� �湮�ڵ�
// => �ٽ� : �Ѱ� ��ҿ� ���� ������ �����ϴ� Ŭ����!!
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { std::cout << e << ", "; }
};

// STL list �� accept �߰�
template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // ������ ���
					// MyList �� std::list �� ������ ������
					// ������� ���� �����ϰ� �Ҽ� �ִ�

	void accept(IVisitor<T>* visitor) override
	{
		// �ڽ��� ��� ��Ҹ� �湮�ڿ��� �����մϴ�.
		for (auto& e : *this) // <== *this�� �ᱹ list
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);		  

	ShowVisitor<int> sv;  
	s.accept(&sv);

}





