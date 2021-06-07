//#include <stdio.h>//표준 입출력 버퍼 
//
//class Date;//클래스 
//class Time {
//	friend void OutToday(Date&, Time&);//프렌드 레퍼런스 인수
//private:
//	int hour, min, sec;
//public:
//	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
//};
//class Date {
//	friend void OutToday(Date&, Time&);//모든 정보 공개
//private:
//	int year, month, day;
//public:
//	Date(int y, int m, int d) { year = y; month = m; day = d; }
//};
//void OutToday(Date& d, Time& t) {
//	printf("%d,%d,%d,%d:%d:%d", d.year, d.month, d.day, t.hour, t.min, t.sec);
//}
//
//int main() {
//	Date d(2018, 06, 29);
//	Time t(12, 34, 56);
//	OutToday(d, t);
//}