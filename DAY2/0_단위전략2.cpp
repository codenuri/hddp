// ��� 1. ���ϴ� ���� �����Լ���
// => template method ���

// ���� : List �� �ƴ϶�, vector, set � ��� �Ʒ� ó�� ����
//      �Ǿ�� �Ѵ�.
//      ����ȭ �ڵ带 �����Ҽ� ����.
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
// ����ȭ ��å�� �����Ϸ��� �Ļ� Ŭ���� ������ �ǵ�
template<typename T>
class ThreadSafeList : public List<T>
{
	// lock()/unlock() ������ �ؼ� ����ȭ ��� ����..
};



List<int> st; 

int main()
{
	st.push_front(10);
}




