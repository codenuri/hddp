class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d; // ok
	
	int* p2 = &d; // error
	
	// 핵심 1. 기반 클래스 포인터로 
	//         파생 클래스 주소를 담을수 있다
	Animal* p3 = &d; // ok. upcasting

	// 핵심 2. Animal* 로는 Animal 에서 상속된
	// 멤버만 접근 가능하다.
	// C++ : 컴파일시간 타입 체크 언어(static type check)
	//       p3 는 Animal* 이므로 Animal 멤버만 허용
	p3->age = 10;	// ok
	p3->color = 10;	// error

	// 핵심 3. Animal* 로 Dog 고유 멤버에 접근하려면
	// 캐스팅 해야 합니다.
	// 단, 이경우 p3를 반드시 Dog를 가리 킨다는 확신이 있어야
	// 합니다.
	static_cast<Dog*>(p3)->color = 10; // ok

}











