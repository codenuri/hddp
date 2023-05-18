
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

	// DCLP : Double Check Locking Pattern
	// 최초 호출 : if 문을 2번 실행하는 오버헤드 존재
	// 나머지 호출: lock/unlock 없이 if 문 한번만 실행
	// => 2004년 발표된 논문에서 아래 코드는 버그입니다. 사용하지 마세요
	//    java 도 마찬가지..

	static Cursor& get_instance()
	{
		if (instance == nullptr)
		{
			mtx.lock();

			if (instance == nullptr)
			{
				instance = new Cursor;

				// 위 한줄은 아래 3줄로 컴파일됩니다.
				// 1. 메모리 할당 : temp =  malloc(sizeof(Cursor))
				// 2. 생성자 호출 : Cursor::Cursor()
				// 3. instance = 할당된메모리주소(temp);

				// 컴파일러 최적화 할때
				// temp 를 제거합니다.
				// 1. 메모리 할당 : instance = malloc(sizeof(Cursor))
				// 2. 생성자 호출 : Cursor::Cursor()
	
			}

			mtx.unlock();
		}

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








