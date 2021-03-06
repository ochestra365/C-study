#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Human {
private:
	char* pname;
	int age;

public:
	Human() {
		pname = new char[1];
		pname[0] = NULL;
		age = 0;
	}
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
		delete[]pname;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main() {
	Human s1("강감찬", 1424);
	Human boy;
	boy = s1;
	boy.intro();
	return 0;
}