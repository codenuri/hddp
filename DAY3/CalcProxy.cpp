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

// Proxy 사용자는 이 동적 모듈에 있는 클래스 이름을 알수도 없고
// 사용해도 안됩니다.
// 약속된 함수를 제공해서 "proxy 객체를 생성" 합니다.
// => Proxy 가 업데이트 되어도 아래 함수이름을 변경되면 안됩니다.

extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}






// cd \     => C: 로 이동

// cd 폴더명 으로 폴더로 이동

// dir/w 로 파일 확인

// cl calcproxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib

// /LD : DLL 로 빌드 옵션






