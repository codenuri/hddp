#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

class Cursor
{
private:
	Cursor()
	{
		std::cout << "start Cursor()" << std::endl;
		std::this_thread::sleep_for(5s);
		std::cout << "finish Cursor()" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
public:
	static Cursor& get_instance()
	{
		std::cout << "get : " << std::this_thread::get_id() << std::endl;
		static Cursor instance;
		std::cout << "finish get : " << std::this_thread::get_id() << std::endl;

		return instance;
	}
};

int main()
{
	std::thread t1(&Cursor::get_instance);
	std::thread t2(&Cursor::get_instance);
	t1.join();
	t2.join();

}








