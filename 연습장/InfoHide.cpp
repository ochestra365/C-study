#include <stdio.h>//표준 입출력버퍼

class Time {//객체 선언
private://보안
	int hour, min, sec;//필드
public://공유
	Time(int h, int m, int s) {//객체 
		SetHour(h);//캡슐화
		SetMinute(m);//캡슐화
		sec = s;
	}
	int GetHour() { return hour; }//값 반환
	void SetHour(int h) {//시간 설정 내부로직 Hiding
		if (h >= 0 && h < 24) {
			hour = h;
		}
	}
	int GetMinute() { return min; }// 값 반환
	void SetMinute(int m) {// 시간 설정 내부 로직 Hiding
		if (m >= 0 && m < 60) {
			min = m;
		}
	}
	int GetSecond() { return sec; }//값 반환

	void OutTime() {//기능 함순
		printf("%d:%d:%d\n", hour, min, sec);
	}
};
int main() {//대체로 함수로 모든 기능을 구현하는 것이 좋다. 안 그럼 코드가 더러어짐
	Time now(12, 34, 56);
	now.SetHour(40);
	now.OutTime();
	now.SetHour(9);
	now.OutTime();
}