#include <iostream>
#include <vector>
#include <list>

// �Ʒ� �ڵ�� ����ȵ˴ϴ�. ������ ���� �ڵ�

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// 1. ��� �����̳�(�÷���)������ �ݺ��ڸ� ������ �־�� �Ѵ�.
	// => �÷����� �������̽��� �ʿ� �ϴ�.
	// => ICollection
	slist_iterator  it1 = s.iterator();
	vector_iterator it2 = v.iterator();

	// 2. ��� iterator �� ������ �����ؾ� �Ѵ�.
	// => �������̽� �ʿ�,
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