#include <iostream>
#include <vector>
#include <string>


// �Ʒ� main �� ����ǵ��� �ڵ带 �ϼ��� ������
// ��, ������ ��� Ŭ������ "Component"

class Component
{
	std::string name;
public:
	Component(const std::string& name) : name(name) {}
	virtual ~Component() {}

	// folder �� �ڽ��� ũ��� ������ ũ�⸦ ���Ҽ��� �ֽ��ϴ�.
	// file, folder ��� get_size() �ʿ�
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
public:
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

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}

