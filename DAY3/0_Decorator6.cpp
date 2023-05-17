#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// ��� ����� Stream �� �Լ� �̸��� ���..
struct Stream
{
	virtual void write(const std::string& data) = 0;
	virtual ~Stream() {}

	// ������ read(), is_open(), flush()
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

int main()
{
	FileStream fs("a.txt");
	fs.write("data");

	NetworkStream ns("127.0.0.1", 4000);
	ns.write("data");

	PipeStream ps("named pipe");
	ps.write("data");
}