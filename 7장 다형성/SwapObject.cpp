#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

template<typename T>
void swap(T& a, T& b) {//Human Ŭ������.(�ϳ��� �ڷ����̴�.)
	T t;
	t = a; a = b; b = t;
}
class Human {
private:
	char* name;
	int age;
public:
	Human() {//������
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}
	Human(const char* aname, int aage) {//2���� �μ��� ���� ������
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}
	Human(const Human& other) {//���������(������������ �Ű������� �� ���� ����������̴�.)==>��ȯ������ �μ� �ϳ��� ��ȯ������
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	Human& operator = (const Human& other) {//������ �����ε�
		if (this != &other) {
			delete[]name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}
	~Human() {//�ı���<-->�Ҹ���
		delete[]name;
	}
	void intro() {//����Լ�
		printf("�̸� = %s, ���� =%d\n", name, age);
	}
};

int main() {
	Human lee("�̽¸�", 10);
	Human park("������", 20);
	lee.intro();
	park.intro();
	swap(lee, park);
	lee.intro();
	park.intro();
}