#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;
public:
	Human(const char* aname, int aage) {
		strcpy(this->name, aname);//�� Ŭ������ ���� �ʵ忡 ������ ���� �����ϰڴ�.
		this->age = aage;// �� Ŭ������ ������ �ʵ忡 ������ ���� �����ϰڴ�.
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	Human kim("�����", 29);
	kim.intro();
}