#include <stdio.h>

void sub(int a) { printf("int : %d\n", a); }
void sub(int* a) { printf("pointer : %p\n", a); }

int main()
{
	int i = 1234, * pi = &i;
	sub(i);
	sub(pi);
	sub(NULL);//�ƹ��͵� ����Ű�� �ʴ� �����ʹ�. 3�� �Լ� ȣ�� int������ ����ϱ� ������ �������� ��µǾ���.
	//�˰� �ִ� �Ͱ� ���̰� ���� ����. �ߺ����ǰ� ��ȣ������. NULL�� ������ 0�̴�.
	//NULL�� ���� ����ȯ�� �ʿ��ϴ�. �߸� ���� ����ų �� ���� ����� �ʷ��� �� �ֵ�.
}