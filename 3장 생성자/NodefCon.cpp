#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human {//클래스 선언
private://멤버변수 이 함수내에서만 참조 가능
	char name[12];//이름을 저장할 배열
	int age;//나이
public://멤버함수
	Human() {
		strcpy(name, "이름없음");
		age = 0;
	}
	Human(const char* aname, int aage) {
		strcpy(name, aname);//메인으로부터 값을 복사 받아서 Human 클래스의 멤버변수로 값을 복사함.
		age = aage;//나이도 마찬가지
	}
	void intro() {//기능함수 실행
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main() {
	Human momo;
	Human arFriend[3];

	Human arFriend[3] = {//클래스 배열 선언
		{Human("문동욱",49)},
		{Human("김유진",49)},
		{Human("박상막",49)},
	};
	arFriend[2].intro();//3번째 배열요소에서 멤버접근지시자를 이용해서 소개 기능을 가진 함수를 실행한다.
}