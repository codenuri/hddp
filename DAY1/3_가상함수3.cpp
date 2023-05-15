// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 핵심 1. 가상함수 재정의시 virtual 은 붙여도 되고
	//			안붙여도 됩니다.
//	virtual void foo() {}

	// 핵심 2. 가상함수 재정의시 실수(오타)가 있어도 에러아닙니다.
	// => 새로운 가상함수로 생각 하므로
//	virtual void fooo() {}
//	virtual void goo(double){}

	// 핵심 3. 가상함수 재정의시 되도록이면 override 붙이세요
	void fooo()      override {}
	void goo(double) override {}
};

int main()
{
}





