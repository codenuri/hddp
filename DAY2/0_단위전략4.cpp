// 방법 3. 정책 클래스를 인터페이스가 아닌
//        템플릿 인자로 교체

// => 단위 전략(policy base design) 

// 장점 : 가상함수가 아닌 인라인 함수.. 빠르다.
// 단점 : 실행시간 정책 교체 안됨

// 정책 클래스가 가져야 하는 조건은 "인터페이스" 가 아닌
// "문서화"로 약속되어야 한다.

template<typename T, 
	typename ThreadModel = nolock> 
class List 
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//......
		tm.unlock();
	}
};
// 동기화 정책을 담은 정책 클래스
class mutex_lock
{
public:
	inline void lock() { }   // mutex.lock();
	inline void unlock() { } // mutex.unlock();
};
class nolock
{
public:
	inline void lock() { }   // empty function
	inline void unlock() { } // 
};
//----------------------------
List<int, mutex_lock> st;
List<int, nolock> st2;

int main()
{
	st.push_front(10);
}




