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

	p1->AddRef(); // ��Ģ 1. proxy �� ����� ������� ����

	ICalc* p2 = p1;
	p2->AddRef(); // ��Ģ 2. ������ ����� ������� ����

	// ��Ģ 3. �����͸� ���̻� ������� ������ ������� ����
	p1->Release();

	std::cout << "-----------" << std::endl;

	p2->Release();

	std::cout << "-----------" << std::endl;

}


