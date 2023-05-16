#include <iostream>
#include <vector>

// 사용자 정의 메모리 할당기 - STL 의 대부분 컨테이너에 전달해서 사용
// cppreference.com 접속해 보세요
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

	v.resize(10); // 이순간 할당기의 allocate() 호출

	std::cout << "------------" << std::endl;

}