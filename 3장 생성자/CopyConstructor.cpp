#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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
	Human(const Human& other) {//�����ڰ� �� ȣ��ȴ�. ���۷����� ������ ���ѹݺ��� ����. ��Ϳ� ����. ���۷����� ������ �����ڰ� �� ȣ��ȴ�.
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}
	~Human() {
		delete[]pname;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};
void printHuman(Human who) {
	who.intro();
}
int main() {
	Human kang("������", 1424);
	Human boy = kang;
	printHuman(boy);
}

//������ : �ʱ�ȭ
//1. ����Ʈ
//2. ���� ������(1. �Ű����� 2. return)
//3. ��ȯ������ �޸𸮿� �̸��� �Ҵ�޴µ� �����ڰ� ȣ��Ǹ鼭 ��μ� ��ü�� ������ ��������� ���̴�. ������ �����ϸ� �ʱ�ȭ�� �ٷ� ������� �Ѵ�.
//4. ���۷����� � �Ϳ� ���� ��Ī�̴�. ��ü�� �����Ǳ� ���� ���� �ʱ�ȭ�� ������� �Ѵ�. �޸� �Ҵ��� ���� �޴� ���̴�.