#include <stdio.h>//ǥ�� ����� ���� ��ó��
#include <string.h>//���� Ưȭ�Լ� ��ó��

class Human {//��ü ����
private://����
	char* pname;//���� �Ҵ� �ʵ�
	int age;//�ʵ�

public:
	Human(const char* aname, int aage) {//�μ� 2�� ������, �̸��� ���(����������), ���̴� ����(������)
		pname = new char[strlen(aname) + 1];//�ο����� �����Ҵ�(null�� ��ħǥ ����)
		strcpy(pname, aname);//��� ���۸� �ܾ�� �����ؼ� ���� ���̺�� �ø�
		age = aage;//�ʵ� ����
	}
	Human(const Human& other) {//���� ���� ���۷��� ��� ������ ���� �ϳ��� ��ü ����(����): �ı��� ���� ���� ����
		pname = new char[strlen(other.pname) + 1];//�ο� ���� �Ҵ�(null)
		strcpy(pname, other.pname);//�������� ���� �ܾ�� ����
		age = other.age;//�������� ���� �ܾ�� ����
	}
	~Human() {//�ı�~�� �����Ϸ��� �ش� ������ ���� ������ �����ش�.
		delete[]pname;//�迭��� �ı�
	}
	void intro() {//���
		printf("%s %d", pname, age);
	}
};
void printHuman(Human who) {//��ü �μ��� �޾Ƽ� ���
	who.intro();//��ü�� ���� ��� 
}
int main() {//����
	Human k("k", 1);//����
	Human b = k;//����
	printHuman(b);//���
}
//DB �����̳� ��Ʈ��ũ ���� �� �������� �ڿ��� �ʿ��� Ŭ������ ���� ������ ����(��Ʈ�� �ϳ�)