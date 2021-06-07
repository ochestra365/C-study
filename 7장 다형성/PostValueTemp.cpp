//#include "cursor.h"
//#include <iostream>
//using namespace std;
//
//template<typename T>//템플릿 생성
//class PosValue {//클래스 생성
//private:
//	int x, y;//멤버변수
//	T value;//T라는 밸류 만들기
//public:
//	PosValue(int ax, int ay, T av) : x(ax), y(ay),value(av){}
//	void outvalue() {
//		gotoxy(x, y);
//		cout << value << endl;
//	}
//};
//
//int main() {
//	PosValue<int> iv(10, 10, 2);//꺾쇠로 캐스팅을 해준다.
//	PosValue<char>cv(25, 5, 'C');//꺾쇠로 캐스팅을 해준다.
//	PosValue<double>dv(30, 15, 3.14);//꺾쇠로 캐스팅을 해준다.
//	iv.outvalue();
//	cv.outvalue();
//	dv.outvalue();
//}