#include <stdio.h>

class Time {
	friend class Date;//Date 객체에서는 Time 객체에 대해 모두 접근 가능하다.
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};
class Date {
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t) {
		printf("%d%d%d%d%d%d", year, month, day, t.hour, t.min, t.sec);
	}
};
int main() {
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}