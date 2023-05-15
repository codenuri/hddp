#include <iostream>
#include <string>
#include <conio.h>


// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� "�����Լ�"��
// 2. ���ϴ� ���� "�ٸ� Ŭ����"��

// ���ؾ� �ϹǷ� ���� ����(�������̽��ʿ�)
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	
	virtual ~IValidator() {}
};
// �ֹ� ��� ��ȣ : 901   1   Ȯ��








class Edit
{
	std::string data;
	
	//------------------------------------------
	IValidator* val = nullptr;
public:
	void setValidate(IValidator* p) { val = p; }
	//------------------------------------------

	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();

			if (c == 13 && 
				(val == nullptr || val->iscomplete(data))  ) break;

			if (val == nullptr || val->validate(data, c) ) // �Է°��� ��ȿ������ �Ǵ���
			{							// �ٸ� ��ü�� ����
				data.push_back(c);
				std::cout << c;
			}

		}
		std::cout << "\n";
		return data;
	}
};

// ���� �پ��� ������ Validator �� �����ϸ� �˴ϴ�.
class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}
};
int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidate(&v); // edit �Է� ���� ��ȿ�� ����
						// �����ϴ� ��å�� ���� v����

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


