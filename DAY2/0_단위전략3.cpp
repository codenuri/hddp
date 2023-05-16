// ��� 2. ���ϴ� ���� �ٸ� Ŭ������
// => strategy pattern ���

// ���� : ����ð��� ��ü �����ϴ�.
//	     ������ s.set_lock(����ȭ��å��ü) �� ���氡��

// ���� : ��å �Լ��� �����Լ� �̴�. ������.

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
	// lock()/unlock() ����.
};




List<int> st; 

int main()
{
	st.push_front(10);
}




