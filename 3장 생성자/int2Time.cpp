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
	explicit Time(int abssec) { //인수 하나가 변환생성자이다. 임시객체를 생성해서 거기에 각각 값들을 변환해서 거기에 멤버를 대입한다.
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	//explicit은 명시적 변환만 허용한다.
	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when) {
	when.OutTime();
}
int main() {
	Time noon(40000);//명시적 변환의 형태
	noon.OutTime();
	//noon = 70000;// 절대초를 넘긴건지 아니면 변수값을 넣은 건지 알수없어서 에러가 뜬다. 모호성이 있어 차단
	//Time now = 60000; 
	//now.OutTime();
	//now = 70000;
	//now.OutTime();

	//printTime(80000);
}
//발생할지도 모를 모호성에 대해서 대비하는 자세를 가져야 한다.