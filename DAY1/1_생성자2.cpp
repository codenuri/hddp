// 1_생성자2-1.cpp
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
// People 에서 파생된 Student 만들어 보세요
// "int id" 만 추가하세요. 생성자로 초기화 해보세요 
class Student : public People
{
	int id;
public:
	// 아래 처럼 하면 에러입니다. People 에 디폴트 생성자가 없습니다.
//	Student(int id) : id(id) {} // Student(int id) : People(), id(id) {}


	Student(const std::string& name, int age, int id)
		: People(name, age), id(id) {}

};

int main()
{
	Student s(? );


	People p1("kim", 20);

//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


