// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// �ٽ� 1. �����Լ� �����ǽ� virtual �� �ٿ��� �ǰ�
	//			�Ⱥٿ��� �˴ϴ�.
//	virtual void foo() {}

	// �ٽ� 2. �����Լ� �����ǽ� �Ǽ�(��Ÿ)�� �־ �����ƴմϴ�.
	// => ���ο� �����Լ��� ���� �ϹǷ�
//	virtual void fooo() {}
//	virtual void goo(double){}

	// �ٽ� 3. �����Լ� �����ǽ� �ǵ����̸� override ���̼���
	void fooo()      override {}
	void goo(double) override {}
};

int main()
{
}





