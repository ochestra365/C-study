//#include <stdio.h>
//class Time {
//public:
//	int hour, min, sec;
//	void OutTime() {
//		printf("%d:%d:%d", hour, min, sec);
//	}
//};
//
//
//int main(){
//	Time now;
//	int Time::* pi;
//
//	pi = &Time::hour;
//	now.*pi = 12;
//	pi = &Time::min;
//	now.*pi = 34;
//	pi = &Time::sec;
//	now.*pi = 56;
//	now.OutTime();
//	return 0;
//}