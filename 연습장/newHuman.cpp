#include <stdio.h>// ǥ�� ����� ��ġ�� ��ó���⿡�� �߰� ��Ŵ
#include <string.h>// ���� Ưȭ �Լ��� ��ó���⿡�� �߰� ��Ŵ

class Human {//��ü ����
private://����
	char* pname;//�ʵ�
	int age;//�ʵ�
public://����
	Human(const char* aname, int aage) {//������ �μ�-> const�� �̸� ������ �����Ҵ�, 
		pname = new char[strlen(aname) + 1];//�ʵ忡 �ΰ��� ������ ����
		strcpy(pname, aname);//���μ��� �ʵ�� ����
		age = aage;//���μ��� �ʵ�� ����
		printf("���� %s", pname);//���� Ȯ�� ���� �߿� x
	}
	~Human() {//�Ҹ�
		printf("��ü �ı� %s", pname);//�ı� Ȯ��
		delete[] pname;//�迭�� Ȯ��
	}
	//���� ��ü ����, �Ʒ��� ��� ����
	void intro() {
		printf("%s ,%d", pname, age);//���Ȯ��
	}
};

int main() {
	Human boy("�����", 12);
	boy.intro();

	Human* leo;//������
	leo = new Human("����", 40);//new �����ڷ� �ʱ�ȭ���� ���� ����
	leo->intro();//�����ʹ� ����� ����Ŵ
	delete leo;//�����͸� �ۻ� ���ϱ� ��ü�� ����ų ������ ����.
	return 0;
}