//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//class Time {//동등한 개념이다. 상하위 관계가 아니다.
//	friend class Date;//데이트 클래스의 모든 멤버변수를 참조한다. 한쪽만 친구다.
//private:
//	int hour, min, sec;//타임 클래스는 시간과 관련된 멤버변수를 가지고 있다.
//public:
//	Time(int h, int m, int s) { hour = h; min = m; sec = s; }//메인에서 복사한 값을 멤버변수로 설정한다. 생성자가 만들어졌다.
//};
//class Date {//데이트 클래스가 나와 있다. (클래스는 가장 좋은 식별자가 해당 객체를 직관적으로 잘 알 수 있게 하는 것이다.
//private:
//	int year, month, day;//데이트 클래스 내에서만 핸들링 할 수 있도록 프라이빗 접근제한자를 설정한다. 데이터의 무결성
//public:
//	Date(int y, int m, int d) { year = y; month = m; day = d; }//메인에서 복사한 값을 넘겨준다. 생성자가 만들어졌다.
//	void OutToday(Time& t) {//만들어진 타임 클래스의 레퍼런스를 인수로 사용한다. 타임 클래스의 객체를 직접 이용하는 것은 타임 객체를 위협하기 때문이다. 기능 함수
//		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",//딱히 중요한 건 아니고
//			year,month, day, t.hour, t.min, t.sec);//데이트 클래스의 멤버변수는 물론이거니와 타임 클래스의 멤버 변수까지 모두 사용할 수 있다.
//	}
//};
//int main() {//항상 메인을 가장 먼저 봐야 한다.
//	Date d(2018, 06, 29);//이후 데이트 클래스를 봐야 한다.
//	Time t(12, 34, 56);//이후 타임 클래스를 봐야한다.
//	d.OutToday(t);
//}