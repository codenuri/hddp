#define USING_GUI
#include "cppmaster.h"

// Proxy 는 update 되고 교체 될수 있어야 한다.

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
	// 아래 코드는 강한 결합 입니다.
	// 새로운 Proxy 가 배포 되면 코드가 수정되게 됩니다.
	// OCP 위반
	// Calc* calc = new Calc;

	// 클라이언트와 Proxy 는 약합결합으로 사용해야 합니다.
	ICalc* calc = ? ? ? ? ;


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}


