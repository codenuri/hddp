
#include <iostream>


// static 멤버 데이타 : 프로그램 최초 실행시 생성자 호출
// static 지역변수   : 함수가 최초 호출될때 생성자 호출
//					  함수가 호출되지 않으면 생성자 호출 안됨

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor()" << std::endl;
	}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// 유일한 객체가 static 멤버 데이타인 모델.
//	Cursor instance; // error
//	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
	std::cout << "main" << std::endl;

	Cursor& c1 = Cursor::get_instance();

}








