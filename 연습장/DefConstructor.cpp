#include <stdio.h>//��ó���⿡�� ǥ������� ���� ȣ��
#include <string.h>//����Ưȭ�Լ� ���

class Human {//��ü
private://����
	char name[12];//�ʵ�
	int age;//�ʵ�

public:
	Human() {//������->�ʱ�ȭ
		strcpy(name, "�̸�����");//�ʱ�ȭ
		age = 0;//�ʱ�ȭ
	}
	void intro() {//���
		printf("�̸� = %s, ���� =%d", name, age);
	}
};

int main() {//����

	Human momo;//��ü ����
	momo.intro();//��� ����
}