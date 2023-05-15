#include <iostream>



// 모든 카메라가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다
class ICamera
{
public:
	virtual void Take() = 0;
};

// 실제 카메라가 없어도 사용자는 규칙 대로만 사용하면 된다.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// 이제 모든 카메라는 규칙을 지켜야 한다.
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





