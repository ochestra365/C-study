#include <stdio.h>//표준 입출력 버퍼 전처리
class Time {//객체 생성
private://보안
	int hour, min, sec;//필드
public:
	Time(int h, int m, int s) {//각 시분초 정해줄때 오버로딩
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//절대초받을 때 처리 오버로딩
		hour = abssec / 3600;
		min=(abssec / 60) % 60;
		sec = abssec % 60;
	}
	void OutTime() {//기능
		printf("%d:%d:%d", hour, min, sec);
	}
};
void printTime(Time when) {
	when.OutTime();
}
int main() {
	Time noon(40000);
	Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();
	printTime(80000);//암시적으로 Time객체로 바뀜
}