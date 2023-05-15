#include <iostream>
#include <string>
#include <conio.h>


// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 "가상함수"로
// 2. 변하는 것을 "다른 클래스"로

// 변해야 하므로 약한 결합(인터페이스필요)
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	
	virtual ~IValidator() {}
};
// 주민 등록 번호 : 901   1   확인





class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();
		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};
int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


