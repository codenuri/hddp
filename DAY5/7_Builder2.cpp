// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// ������ ����
class Korean : public IBuilder
{
public:
	Hat makeHat() override         { return Hat("��"); }
	Uniform makeUnifrom() override { return Unifrom("�Ѻ�"); }
	Shoes makeShoes() override     { return Shoes("�Ѻ�"); }
};
int main()
{
	Korean k;
	Director d;
	d.set_builder(&k); // <<== ���� ������ �����ϸ� ���� ����!!
	Character c = d.construct();
	std::cout << c << std::endl;

}