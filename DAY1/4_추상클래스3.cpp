#include <iostream>



// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�
class ICamera
{
public:
	virtual void Take() = 0;
};

// ���� ī�޶� ��� ����ڴ� ��Ģ ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// ���� ��� ī�޶�� ��Ģ�� ���Ѿ� �Ѵ�.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);

	UHDCamera uhc;
	p.UseCamera(&uhc);
}





