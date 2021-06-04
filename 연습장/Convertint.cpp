#include<stdio.h>//표준 입출력 버퍼
class Time {//객체 생성
private://보안
	int hour, min, sec;//필드
public:
	Time(int h, int m, int s) {//객체 생성
		hour = h;
		min = m;
		sec = s;
	}
	Time(int abssec) {//오버로딩
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	operator int() {//변환 완전한 상호 변환
		return hour * 3600 + min * 60 + sec;
	}
	void OutTime() {//기능
		printf("%d:%d:%d\n", hour, min, sec);
	}
};
int main() {//메인
	Time now(12, 34, 56);//객체 생성
	int i = now;//복사
	printf("i=%d\n", i);
}