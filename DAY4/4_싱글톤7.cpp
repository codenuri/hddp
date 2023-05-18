
#include <iostream>
#include <mutex>

// 자원의 할당과 반납은 되도록이면 직접하지 마세요
// 생성자/소멸자에 의존하세요
// "RAII" 라는 기술
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








