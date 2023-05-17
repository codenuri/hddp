#define USING_GUI
#include "cppmaster.h"

// Client 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll : Proxy가 담긴 동적 모듈

#include "ICalc.h"

ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
					// 리눅스 : dlopen(), 윈도우 : LoadLibrary()

	using F = ICalc* (*)();

	F f = ec_get_function_address(addr, "create");
					// 리눅스 : dlsym(), 윈도우 : GetProcAddress()
	return f();
}


int main()
{
	ICalc* calc = load_proxy();


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}


