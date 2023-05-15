// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age)
		: name(name), age(age)
	{
	}
};
// People ���� �Ļ��� Student ����� ������
// "int id" �� �߰��ϼ���. �����ڷ� �ʱ�ȭ �غ����� 
class Student : public People
{
	int id;
public:
	// �Ʒ� ó�� �ϸ� �����Դϴ�. People �� ����Ʈ �����ڰ� �����ϴ�.
//	Student(int id) : id(id) {} // Student(int id) : People(), id(id) {}


	Student(const std::string& name, int age, int id)
		: People(name, age), id(id) {}

};

int main()
{
	Student s(? );


	People p1("kim", 20);

//	People p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
}


