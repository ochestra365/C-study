#include <stdio.h>

class Simple {//Ŭ���� ����
private:
	int value;//�������
	static int count;//Ŭ�������� �������� ���۵�
public:
	Simple() { count++; }//��ü�� ��������� ī��Ʈ�� �ø���.
	~Simple() { count--; }//��ü�� �ı����� ī��Ʈ�� ���δ�.
	static void InitCount() {//�ʱ��� ī��Ʈ�� 0
		count = 0;
	}
	static void OutCount() {//���� ��ü�� ī��Ʈ ���� �����´�.
		printf("���� ��ü ����= %d\n", count);
	}
};

int Simple::count;//ī��Ʈ�� �����Լ��̱� ������ �ܺο��� �ʱ�ȭ�Ѵ�.
int main() {
	Simple::InitCount();
	Simple::OutCount();
	Simple s, * ps;
	Simple::OutCount();
	ps = new Simple;
	Simple::OutCount();
	delete ps;
	Simple::OutCount();
	printf("ũ�� = %d\n", sizeof(s));
}