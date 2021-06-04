//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
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
//	Human(const char* aname, int aage) {
//		pname = new char[strlen(aname) + 1];
//		strcpy(pname, aname);
//		age = aage;
//		puts("생성자가 만들어졌습니다.");
//	}
//	Human(const Human& other) {
//		pname = new char[strlen(other.pname) + 1];
//		strcpy(pname, other.pname);
//		age = other.age;
//	}
//
//	Human youH(const Human& myH) {
//		Human temp;
//		temp.pname = myH.pname;
//		temp.age = myH.age;
//		return temp;
//	}
//	~Human() {
//		delete[] pname;
//		puts("생성자가 소멸되었습니다.\n");
//	}
//
//	void printHuman() {
//		printf("이름은 %s이고 나이는 %d입니다.\n", pname, age);
//	}
//};
//
//int main(){
//	Human i("박성철", 28);
//	Human u;
//	u.youH(i);
//	i.printHuman();
//	u.printHuman();
//	return 0;
//}
