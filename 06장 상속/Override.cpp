#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human {
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};
class Student : public Human {
protected:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) :Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
	void intro() {
		printf("%d학번 %s입니다.", stunum, name);
	}
};

int main() {
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();
	han.Human::intro();//소속을 적어주면 부모 클래스의 값들이 튀어 나온다.-->범위지정 연산자 소속된 클래스만 쓰면 된다.
}