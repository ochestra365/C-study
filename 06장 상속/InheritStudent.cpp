//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//class Human {
//private:
//	char name[12];
//	int age;
//public:
//	Human(const char* aname, int aage) {
//		strcpy(name, aname);
//		age = aage;
//	}
//	void intro() {
//		printf("�̸� = %s, ���� = %d\n", name, age);
//	}
//};
//
//class Student : public Human {
//private:
//	int stunum;
//public:
//	Student(const char* aname, int aage, int astunum) :Human(aname, aage) {//�θ��� ����� �ڽ�Ŭ�������� �� �����ޱ� ������ �μ��� ����Ѵ�. �ݷ� �ʱ�ȭ�� �Ǿ� �ִ�. �θ� Ŭ������ ����Ʈ ������
//		stunum = astunum;
//	}
//	void study() {
//		printf("���̴� ��, �̻��� ��, �̻� ��\n");
//	}
//};
//int main() {
//	Human kim("�����", 29);//�޸��̶�� �θ�Ŭ���� Ÿ���� ��ü�� ������.
//	kim.intro();
//	Student han("���Ѱ�", 15, 12345);//�׸��� �� ��ü�� ������ ��ӹ޾Ƽ� �ڽ�Ŭ������ �������.
//	han.intro();//�޸��̶�� Ŭ������ �ۺ� Ÿ������ ����� �޾ұ� ������ �� ���� �ִ�. �����Ӱ�
//	han.study();
//	return 0;
//}