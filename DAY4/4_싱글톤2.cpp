
#include <iostream>


class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor()" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// ������ ��ü�� static ��� ����Ÿ�� ��.
//	Cursor instance; // error
	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
	std::cout << "main" << std::endl;

	Cursor& c1 = Cursor::get_instance();

}








