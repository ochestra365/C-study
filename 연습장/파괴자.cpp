#include <stdio.h>//ǥ�� ����� ���۸� ��ó����� �߰��Ѵ�.
#include <string.h>//���ڰ��� Ưȭ �Լ��� ��ó����� �߰��Ѵ�.

class Human {//��ü ����� ��ü ũ��� 5
private://����
	char* pname;//�̸����� �ʵ�
	int age;//���� ���� �ʵ�
public://�Լ� ����
	Human(const char* aname, int aage) {//������. �μ� 2�� 
		pname = new char[strlen(aname) + 1];//�迭�� �ΰ� ���������� ������ �Է�
		strcpy(pname, aname);//�����ؼ� �ʵ忡 ����
		age = aage;//�����ؼ� �ʵ忡 ����
		printf("%s ��ü�� ������ ȣ��Ǿ����ϴ�.\n", pname);
	}
	~Human() {
		printf("%s ��ü�� �ı��Ǿ����ϴ�.\n", pname);
		delete[]pname;// ���ϴ� �ʵ带 �Ҹ���ѹ���
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

int main() {
	Human boy("����ѹ��ź��̿͵η��", 12);//��ü ȣ�⤷
	boy.intro();//��ü ��� ����
}
