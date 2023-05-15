// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog 만 보관 가능한 컨테이너
	std::vector<Animal*> v2; // 동종을 보관하는 컨테이너
							 // 모든 Animal 파생 클래스 객체보관
}