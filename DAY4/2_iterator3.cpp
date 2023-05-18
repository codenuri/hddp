#include <iostream>
#include <vector>
#include <list>

// 아래 코드는 실행안됩니다. 설명을 위한 코드

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// 1. 모든 컨테이너(컬렉션)에서는 반복자를 꺼낼수 있어야 한다.
	// => 컬렉션의 인터페이스가 필요 하다.
	// => ICollection
	slist_iterator  it1 = s.iterator();
	vector_iterator it2 = v.iterator();

	// 2. 모든 iterator 는 사용법이 동일해야 한다.
	// => 인터페이스 필요,
	// => IIterator
	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}