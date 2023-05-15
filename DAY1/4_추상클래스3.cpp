#include <iostream>

// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용하는것
// => 교체 불가능한 경직된 디자인 

// 약한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 
//    규칙을 담은 인터페이스(추상클래스)를 통해서 사용하는것
// => 교체 가능한 유연한 디자인 


// 추상 클래스 : 지켜야 되는 규칙 + 다른 멤버도 있는 경우
// 인터 페이스 : 지켜야 되는 규칙 만 있는 경우
// "지켜야 되는 규칙" : 순수 가상함수를 의미.

// java, C# 에는 abstract, interface 라는 키워드가 존재
// 하지만, C++은 추상 클래스 문법만 존재 합니다.

//-------------------------------------------------
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다" 라고 하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현
//       "모든 카메라는 아래 프로토콜을 채택해야 한다" 라고 도 함(swift)

//class ICamera
struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {} // 인터페이스도 결국 기반 클래스이므로
						// 소멸자를 가상함수로 해야 합니다.
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





