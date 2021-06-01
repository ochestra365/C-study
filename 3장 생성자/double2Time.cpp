//#include <stdio.h>
//
//class Time {
//private:
//	int hour,min,sec;
//public:
//	Time(int h, int m, int s) {
//		hour = h;
//		min = m;
//		sec = s;
//	}
//	Time(int abssec) {
//		hour = abssec / 3600;
//		min = (abssec / 60) % 60;
//		sec = abssec % 60;
//	}
//	Time(double d) {//임시객체가 생성되어 now에 변환되어 사용된다. 변환생성자도 오버로딩이 가능하다.
//		hour = int(d) % 24;
//		min = int((d - int(d)) * 100) % 60;
//		sec = 0;//변환생성자도 인수가 하나인데 다른 타입을 객체형태로 바꾼 것이다.
//		//반대되는 개념은 객체를 다른 타입의 형태로 바꾼 것도 있다. 그것은 변환함수로 불린다.
//	}
//	void OutTime() {
//		printf("현재 시간은 %d:%d:%d입니다. \n", hour, min, sec);
//	}
//};
//int main() {
//	Time now(3.14);
//	now.OutTime();
//}