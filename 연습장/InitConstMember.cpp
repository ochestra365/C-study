#include <stdio.h>//ǥ�� ����� ���� ��ó��

class Some {//��ü ����
public://����
	const int total;//���ȭ
	Some(int atotal) :total(atotal) {}//��� �ʱ�ȭ-->���Թ����� ��� ���� �Ұ� Ư�� �������� �ʱ갪 ó��
	//�ð������� ����� ����ó�� ���� ��ó�� ����
	void OutTotal() { printf("%d\n", total); }//���
};

int main() {
	Some S(5);
	S.OutTotal();
}