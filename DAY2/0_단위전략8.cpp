#include <iostream>
#include <string>

/*
template<typename T,  // char, wchar_t, UTF-8 ��
		 typename Traits= std::char_traits<T>, // �� ��å
	     typename Alloc = std::allocator<T>>  // �޸� �Ҵ��
class basic_string
{
	Alloc ax;
	T* buff;
public:
	// �Ʒ� �ڵ� ������ ������
	bool operator==(const std::basic_string& s)
	{
		return Traits::compare(buff, s.buff);
	}
};
using string = std::basic_string<char>;
using wstring = std::basic_string<wchar_t>;

*/
// cppreference.com   string �˻�

struct MyComparePolicy : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }

    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }

    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, std::size_t n, char a)
    {
        auto const ua(to_upper(a));
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

using ci_string = std::basic_string<char, MyComparePolicy>;

int main()
{
//	std::string s1 = "ABCD";
//	std::string s2 = "abcd";

	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	std::cout << (s1 == s2 ) << std::endl; // 1
}