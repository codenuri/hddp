// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

// 캐릭터를 만드는 클래스
class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// 국가별 빌더
class Korean : public IBuilder
{
public:
	Hat makeHat() override         { return Hat("갓"); }
	Uniform makeUnifrom() override { return Unifrom("한복"); }
	Shoes makeShoes() override     { return Shoes("한복"); }
};
int main()
{
	Korean k;
	Director d;
	d.set_builder(&k); // <<== 국가 선택을 변경하면 빌더 변경!!
	Character c = d.construct();
	std::cout << c << std::endl;

}