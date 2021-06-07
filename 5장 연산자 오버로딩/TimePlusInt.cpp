#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(){}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	const Time operator+(int s)const {
		Time t = *this;
		t.sec += s;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

int main() {
	Time now(11, 22, 33);
	now.OutTime();
	now = now + 1;//이런 형태의 과정을 거쳐서 +연산이 이루어진다. 프로그램을 잘 짜는 사람도 하드웨어나 소프트웨어를 잘 짠다.
	now.OutTime();
}