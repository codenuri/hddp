#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 흐름 내부에 숨은 변하는 코드를 찾아라
	// => 변해야 하는 것을 가상함수로 분리해라

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

			if (validate(c)) // 유효성 확인은 가상함수에 위임.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// Edit 의 파생 클래스를 만들면 값의 유효성 조사 정책을 변경가능
// 합니다.
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


