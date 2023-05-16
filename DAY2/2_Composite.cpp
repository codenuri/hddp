#include <iostream>
#include <vector>
#include <string>


// 아래 main 이 실행되도록 코드를 완성해 보세요
// 단, 공통의 기반 클래스는 "Component"

class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}
	virtual ~Component() {}

	// folder 는 자신의 크기는 없지만 크기를 구할수는 있습니다.
	// file, folder 모두 get_size() 필요
	virtual int get_size() = 0;
};
class File  : public Component
{
	int size;
public:
	File(const std::string& name, int size)
		: Component(name), size(size) {}

	int get_size() override { return size; }
};
class Folder : public Component
{
	std::vector<Component*> v; // 핵심
public:
	Folder(const std::string& name) : Component(name) {}

	void add_item(Component* c) { v.push_back(c); }

	int get_size() override
	{
		int sz = 0;
		for (auto p : v)
			sz += p->get_size();

		return sz;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->add_item(fo1);
	root->add_item(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->add_item(f1);
	root->add_item(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}

