#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	using F = ICalc * (*)();

	F f = (F)ec_get_function_address(addr, "create");
	return f();
}

int main()
{
	ICalc* p1 = load_proxy();

	p1->AddRef(); // 규칙 1. proxy 를 만들면 참조계수 증가

	ICalc* p2 = p1;
	p2->AddRef(); // 규칙 2. 포인터 복사시 참조계수 증가

	// 규칙 3. 포인터를 더이상 사용하지 않으면 참조계수 감소
	p1->Release();

	std::cout << "-----------" << std::endl;

	p2->Release();

	std::cout << "-----------" << std::endl;

}


