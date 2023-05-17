// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

// 사람이 IPod* 로 사용하면
// => 특정 제품(IPod) 만 사용 가능


// 사람이 IMP3* 로 사용하면
// => IMP3 인터페이스를 구현한 모든 제품 사용가능

// 핵심 
// 1. 그런데, IMP3 인터페이스가 수정되면..
// => 모든 MP3 제품이 수정되어야 한다.(어려운일!!)
// => IMP3를 사용하는 Client 코드도 수정되어야 한다.(더 어려운일)

// 2. IMP3 를 사용하는 Client 가 새로운 기능을 요구하면
// => IMP3 인터페이스가 변경되어야 하고
//    모든 MP3 제품이 수정되어야 한다.

// 인터페이스 기반 사용은
// => 제품의 교체는 쉽지만
// => 인터페이스 변경이 나타나는 update 는 어렵다.

class People
{
public:
	void use(IMP3* p)
	{
		p->Play();
		p->Stop();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


