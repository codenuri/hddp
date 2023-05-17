// 1_Adapter4 - decorator8 복사


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


class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s = data + " 암호화됨";

		stream->write(s);
	}
};

class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s = data + " 압축됨";

		stream->write(s);
	}
};

int main()
{

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");

	ZipDecorator zd(&ed);
	zd.write("data");
}
















// C# 언어
// 저장소 클래스		StreamDecorator
// 
// FileStream		GZipStream
// NetworkStream	XmlStream
// PipeStream		HtmlStream

// 구글에서 "C# Stream Decorator" 검색후 - 이미지 보기
