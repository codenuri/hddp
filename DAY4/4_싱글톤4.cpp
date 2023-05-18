
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








