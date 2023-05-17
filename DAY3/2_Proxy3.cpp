#define USING_GUI
#include "cppmaster.h"

// Proxy �� update �ǰ� ��ü �ɼ� �־�� �Ѵ�.

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// �Ʒ� �ڵ�� ���� ���� �Դϴ�.
	// ���ο� Proxy �� ���� �Ǹ� �ڵ尡 �����ǰ� �˴ϴ�.
	// OCP ����
	// Calc* calc = new Calc;

	// Ŭ���̾�Ʈ�� Proxy �� ���հ������� ����ؾ� �մϴ�.
	ICalc* calc = ? ? ? ? ;


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}


