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
	}
	void intro() {
		if ((strlen(pname) < 12) && (age > 0) && (age < 120)) {
			printf("�̸� = %s, ���� =%d\n", pname, age);
		}
		else {
			printf("�̸��� 12�� �̸�, ���̴� 0~120���� �Է°����մϴ�.");
			exit(1);
		}

	}
};
void PrintHuman(Human who) {
	who.intro();
}

int main() {
	printf("�̸��� ���̸� ��������\n(��, �̸��� 12�� �̸�, ���̴� 0~120���� �Է°���\n");
	char name[12];
	int age;
	printf(">�̸� : ");
	scanf("%s", name);
	getchar();//���� ���� ������
	printf(">���� : ");
	scanf("%d", &age);
	Human park(name, age);

	PrintHuman(park);
	return 0;
}