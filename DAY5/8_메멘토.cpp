// 8_메멘토 - 178
#include <iostream>


// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.

	// 방법 1. 함수 인자로 전달하자.
	// Windows의 gdi+ 라이브러ㅣ
	g.DrawLine(0, 0, 100, 100, red, 10);


	// 방법 2. Graphics 의 속성으로 변경하자.
	// IOS 가 사용 - cocoa touch
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100); //좌표만 전달
}









