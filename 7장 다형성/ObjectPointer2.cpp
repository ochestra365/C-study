//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//class Human {
//protected:
//	char name[12];
//	int age;
//
//public:
//	Human(const char* aname, int aage) {
//		strcpy(name, aname);
//		age = aage;
//	}
//	virtual void intro() {
//		printf("�̸� = %s, ����=%d\n", name, age);
//	}
//};
//class Student : public Human {
//protected:
//	int stunum;
//public:
//	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {//�������� ���ֽ� ������ ���
//		stunum = astunum;
//	}
//	void intro() {// ��ӵ� �ڽ�Ŭ������ virtual�� ���������. �ڽ� Ŭ������ �θ� Ŭ������ ����ų �� �ְ� �Ѵ�.
//		//�ٸ� ����� �ǹ̷� virtual�� �ٿ��ش�.
//		printf("%d�й� %s�Դϴ�. \n", stunum, name);
//	}
//	void study() {
//		printf("���̴� ��, �̻��� ��, �̻� ��\n");
//	}
//};
//
//int main() {
//	Human h("����", 10);
//	Student s("���л�", 15, 1234567);
//	Human* pH;
//	Student* pS;
//	pH = &h;//�翬�� ����-->������ �ڷ����� ��ü �ڷ����� �����ϴ�.
//	pS = &s;//�翬�� ����-->������ �ڷ����� ��ü �ڷ����� �����ϴ�.
//	pH = &s;//����--> Human �ڷ��� , Student �ڷ����� �ٸ���. �θ� �ڷ����̶� �ڽ��� ����ų �� �ִ�. upcasting
//	//pS=&h;//����
//	pS = (Student*)&h;//ps �ڷ����� Student��. Human�� h �ڽ��� �θ� ����Ű�� ���̴�.(�ٿ�ĳ����)-->����ȯ
//	pS->intro();
//}