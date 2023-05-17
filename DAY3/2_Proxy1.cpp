#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





// server.zip 압축 풀고
// 새로운 VS 실행해서 열어 보세요

// => x86, debug 로 빌드하세요(32bit만 가능)
// => 버전 맞춰주세요

