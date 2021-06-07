#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main() {
	Time now(12, 34, 56);
	Time then = now;//복사가 가능하다. 자동으로 복사생성자가 호출되기 때문에 클래스의 필드의 값들을 복사해서 사용한다.
	//동일한 타입의 객체를 만들어서 사용하는 것이 가능하다.
	then.OutTime();
}