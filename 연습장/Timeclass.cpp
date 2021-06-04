#include <stdio.h>//표준 입출력 버퍼
class Time {//객체 생성
private://보안
	int hour, min, sec;//필드
public://공유
	Time(int h, int m, int s) {//객체
		hour = h;//메인 복사 이후 필드
		min = m;//메인 복사 이후 필드
		sec = s;//메인 복사 이후 필드
	}
	void OutTime() {//기능
		printf("%d:%d:%d", hour, min, sec);
	}
};

int main() {//메인
	Time now(12, 34, 56);//객체 생성
	Time then = now;//선언 후 대입연산자를 통해 복사, 멤버끼리 1대 1복사
	//다른 쪽은 전혀 영향 x 
	//얕은 복사

	then.OutTime();//모든 기능을 사용 가능
}

/*Time(const Time &other){//복사의 레퍼런스
	hour = other.hour;
	min = other.min;
	sec = other.sec;
*/
