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

// raw 포인터를 대신하는 proxy 를 만들어 봅시다.
// 스마트 포인터
// 기존 포인터에 추가적인 기능을 제공하는 객체
template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }

	sp(const sp& other) : obj(other.obj) { if (obj) obj->AddRef();}
	
	~sp() { if (obj) obj->Release(); }

};

int main()
{
	sp<ICalc> p1 = load_proxy();
	sp<ICalc> p2 = p1;

}


