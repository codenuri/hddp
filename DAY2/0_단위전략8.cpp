#include <iostream>
#include <string>

int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	std::cout << (s1 == s2 ) << std::endl; // 0 ? 1
}