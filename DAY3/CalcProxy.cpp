// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy ����ڴ� �� ���� ��⿡ �ִ� Ŭ���� �̸��� �˼��� ����
// ����ص� �ȵ˴ϴ�.
// ��ӵ� �Լ��� �����ؼ� "proxy ��ü�� ����" �մϴ�.
// => Proxy �� ������Ʈ �Ǿ �Ʒ� �Լ��̸��� ����Ǹ� �ȵ˴ϴ�.

extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}







