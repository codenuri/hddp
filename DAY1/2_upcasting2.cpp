// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog �� ���� ������ �����̳�
	std::vector<Animal*> v2; // ������ �����ϴ� �����̳�
							 // ��� Animal �Ļ� Ŭ���� ��ü����
}