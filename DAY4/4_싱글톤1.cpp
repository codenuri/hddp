// 7_�̱���1 - 123 page
#include <iostream>


// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//         ��𼭵� ������ ������� ���� ������ ��ü

// => ��������!!!
// => ���������� ���� ���ڴ�!!!
// => �׷���, �̱��濡 ���� ���ǵ� ���� �ֽ��ϴ�.


// �Ʒ� �ڵ尡 "Meyer's �̱���" �Դϴ�.
// => effective-C++ �� ������ scott meyer �� ó�� ������ ��
// => ������ ��ü�� static ���������� ��


class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}

	// ��Ģ 2. ���� �����ڿ� ���Կ����ڸ� �����Ϸ� ������ ���ϰ�
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// ��Ģ 3. ���� �Ѱ��� ��ü�� ����� static ��� �Լ�
public:
	static Cursor& get_instance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	Cursor c3 = c1; // �����ڰ� �ƴ� ��������� ���
}








