#include <iostream>
#include <string>

template<typename T,  // char, wchar_t, UTF-8 등
		typename Traits=std::char_traits<T>, // 비교 정책
	typename Alloc = std::allocator<T>>  // 메모리 할당기
class basic_string
{
	Alloc ax;
	T* buff;
public:
	// 아래 코드 생각해 보세요
	bool operator==(const std::basic_string& s)
	{
		return Traits::compare(buff, s.buff);
	}
};
using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;
int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	std::cout << (s1 == s2 ) << std::endl; // 0
}