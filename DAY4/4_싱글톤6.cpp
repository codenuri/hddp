
#include <iostream>
#include <mutex>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* instance;
public:

	// DCLP : Double Check Locking Pattern
	// ���� ȣ�� : if ���� 2�� �����ϴ� ������� ����
	// ������ ȣ��: lock/unlock ���� if �� �ѹ��� ����
	// => 2004�� ��ǥ�� ������ �Ʒ� �ڵ�� �����Դϴ�. ������� ������
	//    java �� ��������..

	static Cursor& get_instance()
	{
		if (instance == nullptr)
		{
			mtx.lock();

			if (instance == nullptr)
			{
				instance = new Cursor;

				// �� ������ �Ʒ� 3�ٷ� �����ϵ˴ϴ�.
				// 1. �޸� �Ҵ� : temp =  malloc(sizeof(Cursor))
				// 2. ������ ȣ�� : Cursor::Cursor()
				// 3. instance = �Ҵ�ȸ޸��ּ�(temp);

				// �����Ϸ� ����ȭ �Ҷ�
				// temp �� �����մϴ�.
				// 1. �޸� �Ҵ� : instance = malloc(sizeof(Cursor))
				// 2. ������ ȣ�� : Cursor::Cursor()
	
			}

			mtx.unlock();
		}

		return *instance;
	}
};
Cursor* Cursor::instance = nullptr;
std::mutex Cursor::mtx;



int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();
}








