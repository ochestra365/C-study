//#include <stdio.h>
//
//class Shape {
//public:
//	virtual void draw() { puts("도형 오브젝트 입니다."); }//과거에 만든 클래스다.
//	//예측을 가지고 클래스를 설계한다.
//};
//class Line : public Shape //상속받아서 draw라는 메서드들을 각 기능에 맞게 생성한다. 미래에 대한 배려
//{
//public:
//	void draw() { puts("선을 긋습니다."); }
//};
//class Circle : public Shape {
//public:
//	void draw() { puts("동그라미 그렸다 치고."); }
//};
//class Rect : public Shape {
//public:
//	void draw() { puts("요건 사각형입니다."); }
//};
//int main() {
//	Shape* ar[] = { new Shape(),new Rect(),new Circle(),new Rect(),new Line() };
//	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
//		ar[i]->draw();
//	}
//	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
//		delete ar[i];
//	}
//	return 0;
//}