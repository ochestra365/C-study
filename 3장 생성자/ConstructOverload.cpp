//#include <stdio.h>
//
//class Time {
//private:
//	int hour, min, sec;
//public:
//	Time(int h, int m, int s) {//매개변수가 없는 생성자가 디폴트 생성자
//		hour = h;//오버로딩을 하면 디폴트 생성자는 사라진다.
//		min = m;
//		sec = s;
//	}
//	Time(int abssec) {
//		hour = abssec / 3600;
//		min = (abssec / 60) % 60;
//		sec = abssec % 60;
//	}
//	void OutTime() {
//		printf("현재 시간은 %d:%d:%d입니다. \n", hour, min, sec);
//	}
//};
//int main() {
//	Time now(12, 30, 40);
//	now.OutTime();
//	Time noon(44000);
//	noon.OutTime();
//}