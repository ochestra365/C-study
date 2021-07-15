#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

class Human 
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	virtual void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};
class Student : public Human {
protected:
	int stunum;
public:
	Student(const char* aname, int aage, int astunum) :Human(aname, aage) {//그대로 상속받아서 쓴다.
		stunum = astunum;
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
	virtual void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};
void IntroSomeBody(Human* pH) {
	pH->intro();
}
int main() {
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);

	IntroSomeBody(&h);
	IntroSomeBody(&s);
	return 0;
}