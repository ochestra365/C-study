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
//		printf("�̸��� %s�Դϴ�. ���̴� %d�Դϴ�.\n", pname, age);
//	}
//	~Human() {
//		delete[]pname;
//		printf("�����Ǿ����ϴ�.\n");
//	}
//};
//
//int main() {
//	Human i("�ڼ�ö",28);
//	i.printHuman();
//}