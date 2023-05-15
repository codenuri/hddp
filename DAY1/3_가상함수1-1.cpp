class Animal
{
public:
	void cry1() {}
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
	p->cry1();
	p->cry2();
}