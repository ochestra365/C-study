//#include <stdio.h>
//
//class Date;
//class Time
//{
//	friend void OutToday(Date&, Time&);
//private:
//	int hour, min, sec;
//public:
//	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
//};
//
//class Date
//{
//	friend void OutToday(Date&, Time&);
//private:
//	int year, month, day;
//public:
//	Date(int y, int m, int d) { year = y; month = m; day = d; }
//};
//
//void OutToday(Date& d, Time& t)
//{
//	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
//		d.year, d.month, d.day, t.hour, t.min, t.sec);
//}
//
//int main()
//{
//	Date d(2018, 06, 29);
//	Time t(12, 34, 56);
//	OutToday(d, t);
//}
//
////복사할 때, 매개변수로 들어갈 때, 리턴할 때==>복사 생성자