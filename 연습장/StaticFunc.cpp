#include <stdio.h>

class Simple {
private:
	int value;
	static int count;

public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {//�ʱⰪ ���� ���� ���� �Լ�
		count = 0;//ī��Ʈ ����
	}
	static void OutCount() {
		printf("%d\n", count);
	}
};
int Simple::count;//��� ��ü�� �ش� ����� ������. �ҼӸ� �����ָ� ��

int main() {
	Simple::InitCount();//ī��Ʈ 0
	Simple::OutCount();
	Simple s, * ps;//ī��Ʈ 1
	Simple::OutCount();
	ps = new Simple;//ī��Ʈ 2
	Simple::OutCount();
	delete ps;//ī��Ʈ 1
	Simple::OutCount();
	printf("%d\n", sizeof(s));
}//ī��Ʈ 0