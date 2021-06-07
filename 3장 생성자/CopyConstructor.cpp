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

//생성자 : 초기화
//1. 디폴트
//2. 복사 생성자(1. 매개변수 2. return)
//3. 변환생성자 메모리에 이름을 할당받는데 생성자가 호출되면서 비로소 객체가 완전히 만들어지는 것이다. 참조를 선언하면 초기화를 바로 시켜줘야 한다.
//4. 레퍼런스는 어떤 것에 대한 별칭이다. 객체가 생성되기 전에 먼저 초기화를 시켜줘야 한다. 메모리 할당을 먼저 받는 것이다.