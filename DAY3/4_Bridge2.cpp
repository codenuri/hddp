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

// ����� IPod* �� ����ϸ�
// => Ư�� ��ǰ(IPod) �� ��� ����

// People �� IMP3 �� ����ϰ� ���� ����
// People ==> MP3 ==> IMP3 �� ������ �������� ������

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
		// Ÿ�̸� ����
		stop();
	}
};
// People �� MP3�� ����ϸ�
// => IMP3 �� ����Ǿ People �� ���� �ȵ�
// => People �� �䱸 ������ �־ MP3�� ó�� �����ϸ� IMP3��
//    ������ �ʿ� ����.
class People
{
public:
	void use(MP3* p) // �긴�� ���
	{
		p->Play();
		p->Stop();

		// ���ο� ��� �䱸
		p->play_one_minute();
	}
};

int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


