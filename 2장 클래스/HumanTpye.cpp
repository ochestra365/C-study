#include <stdio.h>
class Human {
public:
	char name[12];
	int age;
	//�Ӽ��� ũ�⿡ ���� �ν��Ͻ��� ũ�Ⱑ ��������.
	void intro() {//����Լ��� ������ ���� �ʴ´�. �ڵ念���� ����Ǽ� ����Լ��� �� �ν��Ͻ����� �����Ѵ�.
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main() {
	Human arFriend[10] = {
		{"������",49},//�ν��Ͻ� 1 ���� ��ü�� dispoint�� ������ �ִ�.
		{"������",49},//�ν��Ͻ� 2
		{"�ڻ�",49}//�ν��Ͻ� 3
	};
	//�ν��Ͻ��� ũ��� �� �ʵ��� ũ�� �����̴�.
	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();//ù��° ���ڷδ� �� ��ü�� dispoint�� �������ְ�, �Լ����� �����Ѵ�.
}