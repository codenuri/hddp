// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

//void NewYear(Dog* pDog) // Dog ��ü�� ���ް����� �Լ�
void NewYear(Animal* pDog)// ��� ������ ������ �ִ� �Լ�
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











