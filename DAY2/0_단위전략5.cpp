
// 참고 : STL 의 list 는 앞의 예제처럼 동기화가 되는것은 아닙니다.
//      STL 컨테이너는 동기화 지원 안합니다
//      단, 다른 용도로 단위전략을 사용합니다


// STL 의 원리
template<typename T, typename Alloc = std::allocator<T>>
class vector
{
	T* buff;
	Alloc ax;	// 메모리 할당기
				// 앞으로 모든 멤버함수에서는 ax 에 의존해서
				// 메모리 할당/해지를 해야 합니다.
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 
//		buff = new T[n]; // 이렇게 코드를 작성했다면
						// 메모리 할당 방식을 교체 할수 없습니다

		buff = ax.allocate(n);

		ax.deallocate(buff, n); // 해지도.. 단위전략에 의존
	}
};
// std::allocator<T>  : C++ 표준 할당기, new/delete 사용
