#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human {//Ŭ���� ����
private://������� �� �Լ��������� ���� ����
	char name[12];//�̸��� ������ �迭
	int age;//����
public://����Լ�
	Human() {
		strcpy(name, "�̸�����");
		age = 0;
	}
	Human(const char* aname, int aage) {
		strcpy(name, aname);//�������κ��� ���� ���� �޾Ƽ� Human Ŭ������ ��������� ���� ������.
		age = aage;//���̵� ��������
	}
	void intro() {//����Լ� ����
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	Human momo;
	Human arFriend[3];

	Human arFriend[3] = {//Ŭ���� �迭 ����
		{Human("������",49)},
		{Human("������",49)},
		{Human("�ڻ�",49)},
	};
	arFriend[2].intro();//3��° �迭��ҿ��� ������������ڸ� �̿��ؼ� �Ұ� ����� ���� �Լ��� �����Ѵ�.
}