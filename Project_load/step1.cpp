//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//class Human {
//private:
//	char* pname;
//	int age;
//public:
//	Human(){
//		pname = new char[1];
//		pname[0] = NULL;
//		age = 0;
//	}
//	Human(const char *aname, int aage) {
//		pname = new char[strlen(aname) + 1];
//		strcpy(pname, aname);
//		age = aage;
//	}
//	Human(const Human& other) {
//		pname = new char[strlen(other.pname) + 1];
//		strcpy(pname, other.pname);
//		age = other.age;
//	}
//	void printHuman() {
//		printf("이름은 %s입니다. 나이는 %d입니다.\n", pname, age);
//	}
//	~Human() {
//		delete[]pname;
//		printf("해제되었습니다.\n");
//	}
//};
//
//int main() {
//	Human i("박성철",28);
//	i.printHuman();
//}