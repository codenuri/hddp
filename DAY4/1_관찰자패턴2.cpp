//1_����������1 - 94 page
#include <iostream>
#include <vector>


struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// ������ ������ �⺻ �ڵ�� ������ �ʽ��ϴ�.
// ��� Ŭ������ �����ؼ� �����մϴ�.
// ������ ���Ͽ��� ������ ����� "subject" ��� �մϴ�.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{

		for (auto p : v)
			p->update(data);
	}
};
class Table : public Subject 
{
	int value;
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);	
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};

class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};


int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);

	t.edit();
}





