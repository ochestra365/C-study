#include <stdio.h>
class Time;//타임 객체 생성 객체를 인수로 받으려면 Time 클래스가 먼저 선언-->전방선언
class Date {//날짜 객체 생성
private:
	int year, month, day;//날짜에 대한 필드
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }//생성자
	void OutToday(Time& t);//기능함수 캡슐화(레퍼런스 인용)
};

class Time {
	friend void Date::OutToday(Time& t);//공개
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};
void Date::OutToday(Time& t) {
	printf("%d%d%d%d%d%d", year, month, day, t.hour, t.min, t.sec);
}

int main() {
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}