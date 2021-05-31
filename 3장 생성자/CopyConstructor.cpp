#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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
	Human(const Human& other) {//생성자가 또 호출된다. 레퍼런스가 없으면 무한반복에 빠짐. 재귀에 빠짐. 레퍼런스가 없으면 생성자가 또 호출된다.
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}
	~Human() {
		delete[]pname;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};
void printHuman(Human who) {
	who.intro();
}
int main() {
	Human kang("강감찬", 1424);
	Human boy = kang;
	printHuman(boy);
}