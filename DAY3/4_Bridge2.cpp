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

// People 가 IMP3 를 사용하게 하지 말고
// People ==> MP3 ==> IMP3 의 구조로 간접층을 만들자

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p) : impl(p)
	{
		if (impl == 0) 
			impl = new IPod;
	}
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	void play_one_minute()
	{
		play();
		// 타이머 시작
		stop();
	}
};
// People 이 MP3를 사용하면
// => IMP3 가 변경되어도 People 은 수정 안됨
// => People 의 요구 사항이 있어도 MP3가 처리 가능하면 IMP3를
//    변경할 필요 없음.
class People
{
public:
	void use(MP3* p) // 브릿지 사용
	{
		p->Play();
		p->Stop();

		// 새로운 기능 요구
		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


