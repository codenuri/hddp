// 방법 2. 변하는 것을 다른 클래스로
// => strategy pattern 사용

// 장점 : 실행시간에 교체 가능하다.
//	     언제라도 s.set_lock(동기화정책객체) 로 변경가능

// 단점 : 정책 함수가 가상함수 이다. 느리다.

struct ILocker
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ILocker() {}
};

template<typename T> class List
{
	ILocker* locker = nullptr;
public:
	void set_locker(ILocker* p) { locker = p; }

	void push_front(const T& a)
	{
		if (locker) locker->lock();
		//......
		if (locker) locker->unlock();
	}
};

class MutexLocker : public ILocker
{
	// lock()/unlock() 구현.
};




List<int> st; 

int main()
{
	st.push_front(10);
}




