// protected �������� �ǵ�
// => �ڽ��� ��ü�� �����Ҽ� ������(�߻����� ����)
// => �Ļ� Ŭ������ ��ü�� �����Ҽ� �ְ�(��ü���� ����)

// �߻�(abstract) <=> ��ü(concrete)

class Animal
{
//public:	// main ���� �ƴ�
//private:	// main ���� 2�� ��� ����
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
	// ������ ������ ��� ��� ������
	Animal a; // error
	Dog    d; // ok
}



