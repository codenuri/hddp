// 1_Adapter4 - decorator8 복사


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <format> // C++20 부터 지원. 프로젝트 설정에서 "C++20"선택
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

// 핵심 : adapter 는 Stream 상속을 받지 않게 됩니다.
//       write(string) 이 아닌 다른 이름(모양)의 함수 제공.
class StreamWriter //: public Stream
{
	Stream* stream;
public:
	StreamWriter(Stream* s) : stream(s) {}

	template<typename ... ARGS>
	void write(const std::string& fmt, const ARGS& ... args)
	{
		auto s = std::vformat(fmt,
			                 std::make_format_args(args...));

		stream->write(s);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("data");

	// Decorator : 함수 이름이 변경되지 않음, 
	//			   동일 이름의 함수에 기능이 추가되는 것
	//             동일 인터페이스를 구현하게 된다!!!
	ZipDecorator zd(&fs); // 압축 "기능의 추가"
	zd.write("data");


	int n = 10;
	double d = 3.4;

	// adapter : 함수이름이 변경(또는 인자가 변경, 사용법 다름)
	//			기능의 추가 라기 보다는 인터페이스의 변경
	//			사용법 변경
	StreamWriter sw(&fs);
	sw.write("n = {}, d = {}", n, d);
}
















// C# 언어
// 저장소 클래스		StreamDecorator
// 
// FileStream		GZipStream
// NetworkStream	XmlStream
// PipeStream		HtmlStream

// 구글에서 "C# Stream Decorator" 검색후 - 이미지 보기
