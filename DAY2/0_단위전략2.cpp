// 방법 1. 변하는 것을 가상함수로
// => template method 사용

// 단점 : List 뿐 아니라, vector, set 등도 모두 아래 처럼 설계
//      되어야 한다.
//      동기화 코드를 재사용할수 없다.
template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//......
		unlock();
	}
	virtual void lock() {}
	virtual void unlock() {}
};
// 동기화 정책을 변경하려면 파생 클래스 만들라는 의도
template<typename T>
class ThreadSafeList : public List<T>
{
	// lock()/unlock() 재정의 해서 동기화 방법 제공..
};



List<int> st; 

int main()
{
	st.push_front(10);
}




