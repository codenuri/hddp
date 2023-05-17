#define USING_GUI
#include "cppmaster.h"

// Proxy : 다양한 이유로 기존에 존재하던 객체의 대행자를 만드는 패턴

// remote proxy : 원격지 서버에 대한 대행자
// smart  proxy : 기본 객체 접근에 대한 추가적인 기능 수행


// 서버를 대신하는 대행자(proxy)를 설계 합니다.(서버 제작자가 만드는것)
class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}


