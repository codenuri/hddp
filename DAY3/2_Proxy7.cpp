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

	// 진짜 포인터처럼 사용할수 있어야 한다.
	// -> 와 * 연산자 재정의
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	sp<ICalc> p1 = load_proxy();
	sp<ICalc> p2 = p1;

	int n1 = p1->Add(10, 20);

	std::cout << n1 << std::endl; // 30

	//------------------------------------------
	std::shared_ptr<ICalc> sp1(load_proxy());
				// => sp1 의 소멸자가 delete 합니다.
				// => 결국 DLL에서 new 했는데, 실행파일이 delete 한것

	sp<ICalc> p1(load_proxy());
				// => p1은 소멸자가 Release() 호출
				// => 결국 delete 는 DLL 내부에서

}


