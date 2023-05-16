// ��� 3. ��å Ŭ������ �������̽��� �ƴ�
//        ���ø� ���ڷ� ��ü

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
// ����ȭ ��å�� ���� ��å Ŭ����
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




