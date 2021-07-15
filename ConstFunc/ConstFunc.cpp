#include <stdio.h>

class Time {
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) {
		SetTime(h, m, s);
	}
	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	void OutTime() const {//outtime이라는 멤버함수가 상수화가 되는 것이다.
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main() {
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);//객체상수화-->상수화된 멤버변수만 사용할 수 있다.
	//meeting.SetTime(17,00,00);
	meeting.OutTime();
}

//const int func()