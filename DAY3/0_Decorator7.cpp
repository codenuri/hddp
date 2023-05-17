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
		printf("%s ����\n", buff.c_str());
	}
};

int main()
{
	// ���Ͽ� ���� ��ȣȭ �ϴ� ����� �ʿ��ϴ�.
	// �ּ��� ����� ������ ���ô�.

	// 1. ����Ÿ�� ���� ���� ��ȣȭ �ϰ� write.!!
	// => �Ź� ������ �ڵ带 ���� �ۼ��ϸ� �����ϴ�.

	// 2. FileStream ���� ���� �Ļ��� EncrpytFileStream ����
	// => NetworkStream, PipeStream �� ��� Stream �� �Ļ�Ŭ�����ʿ�

	// 3. ��� Stream �� ��� Ŭ������ "Stream"�� �߰�
	// => ���ο� ����� �䱸 �ɶ� ���� Stream���� ???
	// => OCP ����

	// 4. Decorator ������ ����ϸ� ��� ?

	FileStream fs("a.txt");
	fs.write("data");

	EncryptDecorator ed(&fs);
	ed.write("data");	// 1. ����Ÿ�� ��ȣȭ�� �Ŀ�
						// 2. fs.write()

	ZipDecorator zd(&ed);
	zd.write("data");	// 1. ����Ÿ ����
						// 2. ed.write()
}