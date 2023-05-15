class Animal
{
public:
	// non-virtual : 포인터 타입으로 함수 호출을 결정. 빠르다.
	void cry1() {}
	
	// virtual : 포인터 타입이 아닌 메모리 조사후 함수를 결정
	//			느리다.
	virtual void cry2() {}
};
class Dog : public Animal
{
public:
	void cry1() {}
	virtual void cry2() {}
};
int main()
{
	Dog dog;
	Animal* p = &dog;
	p->cry1(); // call Animal::cry1
	p->cry2();
}