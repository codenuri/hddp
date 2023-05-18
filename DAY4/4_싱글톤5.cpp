
#include <iostream>
#include <mutex>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* instance;
public:
	// 아래 함수가 100번 호출된다고 생각해 보세요 
	// 최초 호출시 : 객체 생성
	// 나머지 99번 : 객체 생성 안함. 단지 만들어진 객체만 반환.. 
	//				그런데..lock/unlock 을 수행해야 합니다.
	static Cursor& get_instance()
	{
		mtx.lock();

		if (instance == nullptr)
			instance = new Cursor;

		mtx.unlock();

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








