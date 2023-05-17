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


// ����� IMP3* �� ����ϸ�
// => IMP3 �������̽��� ������ ��� ��ǰ ��밡��

// �ٽ� 
// 1. �׷���, IMP3 �������̽��� �����Ǹ�..
// => ��� MP3 ��ǰ�� �����Ǿ�� �Ѵ�.(�������!!)
// => IMP3�� ����ϴ� Client �ڵ嵵 �����Ǿ�� �Ѵ�.(�� �������)

// 2. IMP3 �� ����ϴ� Client �� ���ο� ����� �䱸�ϸ�
// => IMP3 �������̽��� ����Ǿ�� �ϰ�
//    ��� MP3 ��ǰ�� �����Ǿ�� �Ѵ�.

// �������̽� ��� �����
// => ��ǰ�� ��ü�� ������
// => �������̽� ������ ��Ÿ���� update �� ��ƴ�.

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


