#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
	std::string data;
public:
	// ���뼺�� �������� �и�
	// => ������ ���� �帧 ���ο� ���� ���ϴ� �ڵ带 ã�ƶ�
	// => ���ؾ� �ϴ� ���� �����Լ��� �и��ض�

	virtual bool validate(char c)
	{
		return true;
	}


	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c)) // ��ȿ�� Ȯ���� �����Լ��� ����.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// Edit �� �Ļ� Ŭ������ ����� ���� ��ȿ�� ���� ��å�� ���氡��
// �մϴ�.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};
int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


