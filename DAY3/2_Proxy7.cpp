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

	// ��¥ ������ó�� ����Ҽ� �־�� �Ѵ�.
	// -> �� * ������ ������
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
				// => sp1 �� �Ҹ��ڰ� delete �մϴ�.
				// => �ᱹ DLL���� new �ߴµ�, ���������� delete �Ѱ�

	sp<ICalc> p1(load_proxy());
				// => p1�� �Ҹ��ڰ� Release() ȣ��
				// => �ᱹ delete �� DLL ���ο���

}


