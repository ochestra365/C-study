#include <iostream>

struct Human {
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;
	void view(); 
};
void Human::view() {//����ü�� ������� �����ڰ� �⺻������ public���� ������� �ִ�.
	printf("���� �̸��� %s�̰� �̰� Ű�� %f�̰� �����Դ� %f�̰� ���̴� %d�̰� �������� %c�̴�.", name, height, weight, age, blood);
}//Ŭ������ �Ӽ��� ��ɵ��� �� �ִ�. ����ü���� ����Լ��� �߰��� �� ���� Ŭ�����̴�.
int main() {
	Human my = { "�ڼ�ö",168,64,28,'b'};
	my.view();
	return 0;
}