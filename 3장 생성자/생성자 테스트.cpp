#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

class CTest {
private:
	int m_num;

public:
	CTest() {
		printf("����Ʈ ������!\n");
	}
	CTest(int num) {//�����ڴ� �ʱ�ȭ�����ִ� ������ �Ѵ�. �ݴ�� �Ҹ��ڵ� �ʿ��ϴ�
		m_num = num;
		printf("������ ȣ�� : %d\n", m_num);
	}
	void getData() {
		printf("%d\n", m_num);
	}
};
int main() 
{
	//�⺻ �ڷ���
	int a = 10;
	int b(20);//���ο� ������ ���� ����
	int c(a);
	printf("%d %d %d\n", a, b, c);
	//����� �ڷ���
	CTest c1(100);//����Ʈ �����ڴ� �μ��� ����. �����ϱ� ���ؼ��� �����ڸ� �ϳ� ����� ��� �Ѵ�. �μ� 1���� ������ ȣ��
	CTest c2;//��������� � �����ڸ� ����� �Ǹ� �����Ϸ����� �����ϴ� ����Ʈ �����ڸ� �� �� �� ����.
	CTest c3(c1);//��������� ȣ�� (���� ����)
	c3.getData();
	printf("%d, %d\n", a,b);
	return 0;
}
/*
������ : �ʱ�ȭ
1. ����Ʈ
2. ���������(1. �Űܺ���, 2. return )
3. ��ȯ������ : �μ��� 1��
����Ʈ �����ڿ� ��������ڴ� �ڵ����� �����Ϸ��� �������ִ� ���̴�.
*/