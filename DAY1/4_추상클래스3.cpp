#include <iostream>

// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� Ŭ���� �̸��� ���� ����ϴ°�
// => ��ü �Ұ����� ������ ������ 

// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� 
//    ��Ģ�� ���� �������̽�(�߻�Ŭ����)�� ���ؼ� ����ϴ°�
// => ��ü ������ ������ ������ 


// �߻� Ŭ���� : ���Ѿ� �Ǵ� ��Ģ + �ٸ� ����� �ִ� ���
// ���� ���̽� : ���Ѿ� �Ǵ� ��Ģ �� �ִ� ���
// "���Ѿ� �Ǵ� ��Ģ" : ���� �����Լ��� �ǹ�.

// java, C# ���� abstract, interface ��� Ű���尡 ����
// ������, C++�� �߻� Ŭ���� ������ ���� �մϴ�.

//-------------------------------------------------
// ��� ī�޶� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�" ��� ���� ����
//       "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ��
//       "��� ī�޶�� �Ʒ� ���������� ä���ؾ� �Ѵ�" ��� �� ��(swift)

//class ICamera
struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {} // �������̽��� �ᱹ ��� Ŭ�����̹Ƿ�
						// �Ҹ��ڸ� �����Լ��� �ؾ� �մϴ�.
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





