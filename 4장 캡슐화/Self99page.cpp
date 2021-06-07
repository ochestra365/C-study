#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "cursor.h"

class Human {
private:
	char* pname;
	int age;
public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}
	Human(const Human& other) {
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}
	~Human() {
		delete[] pname;
		printf("생성자 소멸\n");
	}
	void intro() {
		if ((strlen(pname) < 12) && (age > 0) && (age < 120)) {
			printf("이름 = %s, 나이 =%d\n", pname, age);
		}
		else {
			printf("이름은 12자 미만, 나이는 0~120까지 입력가능합니다.");
			exit(1);
		}

	}
};
void PrintHuman(Human who) {
	who.intro();
}
void print_line() {
	printf("\n");
	for (int i = 0; i < 50; i++) {
		printf("=");
	}
	printf("\n");
}
int main() {
	printf("이름과 나이를 적으세요\n(단, 이름은 12자 미만, 나이는 0~120까지 입력가능\n");
	print_line();
	while (1) {
		char name[12];
		int age;
		printf(">이름 : ");
		scanf("%s", name);
		getchar();//개행 버퍼 없애줌
		printf(">나이 : ");
		scanf("%d", &age);
		Human park(name, age);
		PrintHuman(park);
	}
	
	return 0;
}