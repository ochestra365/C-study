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
//		puts("�����ڰ� ����������ϴ�.");
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
//		puts("�����ڰ� �Ҹ�Ǿ����ϴ�.\n");
//	}
//
//	void printHuman() {
//		printf("�̸��� %s�̰� ���̴� %d�Դϴ�.\n", pname, age);
//	}
//};
//
//int main(){
//	Human i("�ڼ�ö", 28);
//	Human u;
//	u.youH(i);
//	i.printHuman();
//	u.printHuman();
//	return 0;
//}
