#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;
public:
	Human(const char* aname, int aage) {
		strcpy(this->name, aname);//이 클래스의 네임 필드에 복사한 값을 대입하겠다.
		this->age = aage;// 이 클래스의 에이지 필드에 복사한 값을 대입하겠다.
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main() {
	Human kim("김상형", 29);
	kim.intro();
}