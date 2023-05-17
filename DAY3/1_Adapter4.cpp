// 1_Adapter4 - decorator8 ����


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <format> // C++20 ���� ����. ������Ʈ �������� "C++20"����
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
		printf("%s ����\n", buff.c_str());
	}
};


class EncryptDecorator : public Stream
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& data) override
	{
		auto s = data + " ��ȣȭ��";

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
		auto s = data + " �����";

		stream->write(s);
	}
};

// �ٽ� : adapter �� Stream ����� ���� �ʰ� �˴ϴ�.
//       write(string) �� �ƴ� �ٸ� �̸�(���)�� �Լ� ����.
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

	// Decorator : �Լ� �̸��� ������� ����, 
	//			   ���� �̸��� �Լ��� ����� �߰��Ǵ� ��
	//             ���� �������̽��� �����ϰ� �ȴ�!!!
	ZipDecorator zd(&fs); // ���� "����� �߰�"
	zd.write("data");


	int n = 10;
	double d = 3.4;

	// adapter : �Լ��̸��� ����(�Ǵ� ���ڰ� ����, ���� �ٸ�)
	//			����� �߰� ��� ���ٴ� �������̽��� ����
	//			���� ����
	StreamWriter sw(&fs);
	sw.write("n = {}, d = {}", n, d);
}
















// C# ���
// ����� Ŭ����		StreamDecorator
// 
// FileStream		GZipStream
// NetworkStream	XmlStream
// PipeStream		HtmlStream

// ���ۿ��� "C# Stream Decorator" �˻��� - �̹��� ����
