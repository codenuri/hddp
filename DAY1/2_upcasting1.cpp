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
	
	// �ٽ� 1. ��� Ŭ���� �����ͷ� 
	//         �Ļ� Ŭ���� �ּҸ� ������ �ִ�
	Animal* p3 = &d; // ok. upcasting

	// �ٽ� 2. Animal* �δ� Animal ���� ��ӵ�
	// ����� ���� �����ϴ�.
	// C++ : �����Ͻð� Ÿ�� üũ ���(static type check)
	//       p3 �� Animal* �̹Ƿ� Animal ����� ���
	p3->age = 10;	// ok
	p3->color = 10;	// error

	// �ٽ� 3. Animal* �� Dog ���� ����� �����Ϸ���
	// ĳ���� �ؾ� �մϴ�.
	// ��, �̰�� p3�� �ݵ�� Dog�� ���� Ų�ٴ� Ȯ���� �־��
	// �մϴ�.
	static_cast<Dog*>(p3)->color = 10; // ok

}











