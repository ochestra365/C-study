#include <stdio.h>//ǥ�� ����� ���� ��ó��

class Some {//��ü ����
public://����
	int& total;//���۷���
	Some(int &atotal):total(atotal){}//�ʱ�ȭ ����Ʈ ���۷���
	void OutTotal() { printf("%d", total); }
};
int main() {
	int v = 8;
	Some S(v);
	S.OutTotal();
}

//����� ���۷����� ����ϱ� ���� ���� ����� �������� �Ѵ�.