//1_����������1 - 94 page
#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// ��� �׷����� �ڽ��� � ���̺��� �����ϴ��� �˾ƾ� �Ѵ�.
	Subject* subject = nullptr;
};


// ������ ������ �⺻ �ڵ�� ������ �ʽ��ϴ�.
// ��� Ŭ������ �����ؼ� �����մϴ�.
// ������ ���Ͽ��� ������ ����� "subject" ��� �մϴ�.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 
		p->subject = this;
	}
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

	int data[4] = { 1,2,3,4 };
public:
	
	int* get_data() { return data; }

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

		// ������ ����� ����Ǿ��ٰ� �뺸�� �Դ�.
		// ���� ��� ���ߴ��� �����ϱ� ����
		// ������ ��� ����(��� �Լ�) �Ѵ�.

		//int* data = subject->get_data(); // error

		// subject �� ���� "Table ��ü" �� ����Ű����
		// Ÿ���� Subject* �Դϴ�.
		// ĳ������ �ʿ� �մϴ�.
		// ������ ���� ����.. ĳ���� �ϴ� �ڵ尡 ���� �����մϴ�.

		Table* table = static_cast<Table*>(subject);
					// => down casting

		int* data = table->get_data();


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





