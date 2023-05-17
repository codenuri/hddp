#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& buff) 
	{
		printf("%s 쓰기\n", buff.c_str() );
	}
};

int main()
{
	// C언어 : 사용자가 직접 자원을 관리해야 합니다.
	FILE* f = fopen("a.txt", "wt");

	fclose(f);

	// C++ : 소멸자로 자원 관리 가능
	FileStream fs("a.txt");
	fs.write("hello");

	// 파일을 닫지 않아도 소멸자에서 fclose수행
}