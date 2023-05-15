// protected 생성자의 의도
// => 자신의 객체는 생성할수 없지만(추상적인 존재)
// => 파생 클래스의 객체는 생성할수 있게(구체적인 존재)

// 추상(abstract) <=> 구체(concrete)

class Animal
{
//public:	// main 에러 아님
//private:	// main 에서 2줄 모두 에러
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {} // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a; // error
	Dog    d; // ok
}



