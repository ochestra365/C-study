#include <stdio.h>

struct SHuman {//단지 정보만 저장
	char name[12];
	int age;

	void intro();//기능을 실현
};

void SHuman::intro() {//기능에 대한 정의(어디에 소속된 범위인 지 알려줘야 함)
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main() {
	SHuman kim = { "김상형",29 };
	kim.intro();
}