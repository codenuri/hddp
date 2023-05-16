// 방법 3. 정책 클래스를 인터페이스가 아닌
//        템플릿 인자로 교체

template<typename T, typename ThreadModel> class List
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




