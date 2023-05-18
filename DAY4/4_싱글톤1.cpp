// 7_싱글톤1 - 123 page
#include <iostream>


// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//         어디서든 동일한 방법으로 접근 가능한 객체

// => 전역변수!!!
// => 전역변수는 보통 나쁘다!!!
// => 그래서, 싱글톤에 대한 비판도 많이 있습니다.


// 아래 코드가 "Meyer's 싱글톤" 입니다.
// => effective-C++ 의 저자인 scott meyer 가 처음 제안한 모델
// => 유일한 객체가 static 지역변수인 모델


class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사 생성자와 대입연산자를 컴파일러 만들지 못하게
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// 규칙 3. 오직 한개의 객체만 만드는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	Cursor c3 = c1; // 생성자가 아닌 복사생성자 사용
}








