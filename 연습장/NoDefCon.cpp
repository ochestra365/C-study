#include <stdio.h>//ǥ������� ���� ��ó���� ó��
#include <string.h>//����Ưȭ�Լ� ó��

class Human {//��ü����
private://����
	char name[12];//�ʵ�
	int age;//�ʵ�

public://����
	Human(const char* aname, int aage) {//������ �̸��� ��� ���̴� ����
		strcpy(name, aname);//���ο��� ������ �����ؼ� �ʵ忡 ����
		age = aage;//���ο��� ������ �����ؼ� �ʵ忡 ����
	}
	void intro() {//���
		printf("%s %d", name, age);
	}
};

int main() {//������ �޸�
	//Human momo;//����
	//Human arFriend[3];//�����ڰ� �ݵ�� �ñ״�ó�� �ֵ��� ��Ģ�� ����
	Human arFriend[3] = {//Ŭ���� �迭, ������ �Ϸ��� ������
		{Human("������",40)},//��ü
		{Human("������",40)},//��ü
		{Human("�ڻ�",40)}, //��ü
	};
	arFriend[2].intro();//�ι��� �迭����� ��� ����
}

//Human(const char *aname="", int aage=0); // ����Ʈ 