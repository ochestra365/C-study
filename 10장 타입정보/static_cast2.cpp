#include <stdio.h>

class Parent {};
class Child:public Parent{};
int main() {
	Parent P, * pP;//�����ͳ��� ����� ��ȯ�� �Ұ��� �ϴ�.
	Child C, * pC;
	int i = 1234;
	//�������� �����ϴ� �⺻ �ڷ����� ��ȯ�� �ƴ϶�� �ȵȴ�.
	pP = static_cast<Parent*>(&C);//����-->�ڽ������� �ּҸ� �θ� ���·� �ٲ۴�.
	pC = static_cast<Child*>(&P);//���������� ����
	//pP = static_cast<Parent*>(&i);//�Ұ�
	//pC = static_cast<Child*>(&i);//����
}