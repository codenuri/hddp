#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string& data) = 0;
	virtual ~Stream() {}
};


class FileStream : public Stream
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
		printf("%s 쓰기\n", buff.c_str());
	}
};

int main()
{
	// 파일에 쓸때 암호화 하는 기능이 필요하다.
	// 최선의 방법을 생각해 봅시다.

	// 1. 데이타를 먼저 직접 암호화 하고 write.!!
	// => 매번 유사한 코드를 직접 작성하면 불편하다.

	// 2. FileStream 으로 부터 파생된 EncrpytFileStream 제공
	// => NetworkStream, PipeStream 등 모든 Stream 에 파생클래스필요

	// 3. 모든 Stream 의 기반 클래스인 "Stream"에 추가
	// => 새로운 기능이 요구 될때 마다 Stream변경 ???
	// => OCP 위반

	// 4. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");	// 1. 데이타를 암호화한 후에
						// 2. fs.write()

	ZipDecorator zd(&ed);
	zd.write("data");	// 1. 데이타 압축
						// 2. ed.write()
}