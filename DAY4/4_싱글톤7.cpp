
#include <iostream>
#include <mutex>

// �ڿ��� �Ҵ�� �ݳ��� �ǵ����̸� �������� ������
// ������/�Ҹ��ڿ� �����ϼ���
// "RAII" ��� ���
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};





class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* instance;
public:


	static Cursor& get_instance()
	{
		lock_guard<std::mutex> g(mtx);
//		mtx.lock();

		if (instance == nullptr)
			instance = new Cursor;

//		mtx.unlock();

		return *instance;
	}

};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::mtx;



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








