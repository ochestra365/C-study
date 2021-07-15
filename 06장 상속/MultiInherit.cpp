#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d%d%d", year, month, day); }
};

class Time {
protected:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() { printf("%d:%d:%d", hour, min, sec); }
};

class DateTime : public Date, public Time {//다중상속은 컴마 찍어서 어떤 지정자로 상속받는 지 표현하면 된다.
private:
	bool bEngMessage;
	int milisec;
public:
	DateTime(int y, int m, int d, int h, int min, int s, int ms, bool b = false) :Date(y, m, d), Time(h, min, s) {//상속받는 모두 멤버변수들을 초기화시켜줘야 한다.
		milisec = ms;
		bEngMessage = b;
	}
	void OutNow() {
		printf(bEngMessage ? "Now is" : "지금은 ");
		OutDate();
		putch(' ');
		OutTime();
		printf(".%d", milisec);
		puts(bEngMessage ? "." : "입니다.");
	}
};
int main() {
	DateTime now(2017, 6, 29, 12, 30, 58, 99);
	now.OutNow();
}