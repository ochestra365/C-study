#include <stdio.h>//��ó���� ǥ�� ����� ����
#include <string.h>// ���� Ưȭ�Լ�

class Human {//��ü ����
private://����
	char* pname;//�����Ҵ� �ʵ�
	int age;//�ʵ�
public:
	Human(const char* aname, int aage) {//�μ� 2�� ������(�ʱ�ȭ) 
		pname = new char[strlen(aname) + 1];//���� ���� null���� �ʱ�ȭ�� new ���� �޸� �� �� �����Ƿ� ���� �ֹ�
		strcpy(pname, aname);//������ Ÿ���� ����
		age = aage;//����
	}
	~Human() {//�Ҹ�	
		delete[]pname;//����
	}
	void intro() {//���
		printf("%s %d", pname, age);
	}
};

int main() {//����
	Human k("k", 12);
	Human b = k;
	b.intro();
}
//����
//�̸��� ���ȴµ� �� ������ �ϴ� �� �Ǵ� ���̴�. ���� ���� �߻� ���� �����