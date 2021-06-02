//#include <stdio.h>
//
//class MathCalc {
//private:
//	const double pie;//키워드를 const로 해놓았다.
//public:
//	MathCalc(double apie) : pie(apie){}//상수 멤버는 콜론으로 초기화시킴. 상수는 선언과 동시에 초기화를 시켜줘야 한다. 레퍼런스 때 사용
//	void DoCalc(double r) {
//		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
//	}
//};
////객체이름으로 메모리 할당. 생성자가 호출되어 초기화되면 완벽한 객체가 생성된다.
//int main() {
//	MathCalc m(3.1416);
//	m.DoCalc(5);
//}