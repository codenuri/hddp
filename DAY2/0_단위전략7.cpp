#include <iostream>
#include <vector>

// ����� ���� �޸� �Ҵ�� - STL �� ��κ� �����̳ʿ� �����ؼ� ���
// cppreference.com ������ ������
template<typename T>
class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		printf("allocate : %p, %d cnts\n", p, sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %p, %d cnts\n", p, sz);
		free(p);
	}

	using value_type = T;
	debug_alloc() {}
	
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};

int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "------------" << std::endl;

	v.resize(10); // �̼��� �Ҵ���� allocate() ȣ��

	std::cout << "------------" << std::endl;

}