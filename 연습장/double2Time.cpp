#include <stdio.h>//표준 입출력 버퍼 전처리
class Time {//객체 선언
private://보안
	int hour, min, sec;//필드

public://공유
	Time(int h, int m, int s) {//복사 ->필드
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//절대초 처리 오버로딩
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	Time(double d) {//형변환 처리 오버로딩
		hour = int(d) % 24;
		min=(int(d - int(d)) * 100) % 60;
		sec = 0;
	}
	void OutTime() {//기능
		printf("%d:%d:%d", hour, min, sec);
	}
};
int main() {
	Time now(3.14);
	now.OutTime();
}