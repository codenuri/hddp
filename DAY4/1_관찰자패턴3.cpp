//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 그래프도 자신이 어떤 테이블을 관찰하는지 알아야 한다.
	Subject* subject = nullptr;
};


// 관찰자 패턴의 기본 코드는 변하지 않습니다.
// 기반 클래스를 설계해서 제공합니다.
// 관찰자 패턴에서 관찰의 대상을 "subject" 라고 합니다.
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

		// 관찰이 대상이 변경되었다고 통보가 왔다.
		// 이제 어떻게 변했는지 조사하기 위해
		// 관찰의 대상에 접근(멤버 함수) 한다.

		//int* data = subject->get_data(); // error

		// subject 는 실제 "Table 객체" 를 가리키지만
		// 타입이 Subject* 입니다.
		// 캐스팅이 필요 합니다.
		// 관찰자 패턴 사용시.. 캐스팅 하는 코드가 많이 등장합니다.

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





