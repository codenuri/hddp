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

// raw �����͸� ����ϴ� proxy �� ����� ���ô�.
// ����Ʈ ������
// ���� �����Ϳ� �߰����� ����� �����ϴ� ��ü
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


