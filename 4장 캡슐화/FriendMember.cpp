#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class Time;//하위 객체를 선언해준다.
class Date {
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }//복사값을 받아서 멤버변수로 넘겨준다.
	void OutToday(Time& t);//타임 클래스의 레퍼런스를 도출한다.
};

class Time {
	friend void Date::OutToday(Time& t);//데이트 클래스에 소속되었다. 범위지정 그래야 복사 생성자가 불러와진다. 참조해야 한다.
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }//복사값을 받아서 멤버변수로 넘겨준다.
};
void Date::OutToday(Time& t) {//인수로 타임클래스의 레퍼런스를 모두 전달해준다.
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d이다.",year,month,day,t.hour,t.min,t.sec);//딱히 중요한 거 아니다.
}
int main() {
	Date d(2018, 06, 29);//데이트 클래스 본다
	Time t(12, 34, 56);//타임클래스를 ㅋ본다.
	d.OutToday(t);//데이트 클래스의 오늘날을 출력한다.
}