// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	struct Memento
	{
		int penWidth = 1;
		int penColor = 0;

		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};

	std::map<int, Memento*> memento_map;
	int key = 0;
public:
	int Save()
	{
		Memento* m = new Memento(penWidth, penColor);
		memento_map[++key] = m;
		return key;
	}

	void Restore(int k)
	{
		penWidth = memento_map[k]->penWidth;
		penColor = memento_map[k]->penColor;
	}

	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};



int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // 메멘토 패턴
							// 객체가 자신의 상태를 스스로 저장/복구
							// 할수 있게 한다.
							// 캡슐화를 위배 하지 않고 저장 복구가 가능

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);
}









