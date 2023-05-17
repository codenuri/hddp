#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;



class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};
// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP Server 를 만들려면 "몇개의 클래스를 사용해서 몇가지 절차를 거쳐야 합니다."
// 이런 과정을 단순화 하는 상위 레벨의 클래스를 제공하면 편리합니다.
// ==> facade 패턴

class TCPServer
{	
	NetworkInit init;
	Socket sock{ SOCK_STREAM };
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};
int main()
{
	TCPServer server;
	server.Start("127.0.0.1", 4000);

}



// 3차 API : 사용하기 쉽게 하기 위한 포괄적 개념의 인터페이스
//			 TCPServer 등, 
//---------------------------------------------------
// 2차 API : 객체지향. C언어와 1:1 매칭되는 기능의 클래스
//               단일 책임의 원칙(Single Responsibility Principle)
//------------------------------------------
// 1차 API : C언어기반 함수, 분야별 수백 ~ 수천개
//---------------------------------------
// OS      : linux, windows, osx    모두 C언어




// 참고

// 아래 3줄 초기화는 모두 가능
int n1 = 0;
int n2(0);
int n3{ 0 };

// 그런데.. 멤버일 때는 () 는 안됨.
class A
{
	int n1 = 0;
	//	int n2(0); // error
	int n3{ 0 };
};