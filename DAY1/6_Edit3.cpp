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

			if (val == nullptr || val->validate(data, c) ) // 입력값의 유효성여부 판단을
			{							// 다른 객체에 위임
				data.push_back(c);
				std::cout << c;
			}

		}
		std::cout << "\n";
		return data;
	}
};

// 이제 다양한 종류의 Validator 만 제공하면 됩니다.
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
	e.setValidate(&v); // edit 입력 값의 유효성 여부
						// 조사하는 정책을 담은 v전달

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


