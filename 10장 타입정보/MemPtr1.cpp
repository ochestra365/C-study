#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class Calc {
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void DoCalc(void (Calc::* fp)(int, int), int a, int b) {//�Լ��� �̸��� �����ʹ�. ����� ��ġ�� ��ġ�� ���Ͻ�Ŵ
		puts("������");
		printf("%d�� %d�� ������", a, b);
		(this->*fp)(a, b);
		puts("�̻�");
	}
};

int main() {
	int ch;
	Calc c;
	int a = 3, b = 4;
	void(Calc:: * arop[3])(int, int) = { &Calc::Op1,&Calc::Op2,&Calc::Op3 };//������ �迭
	puts("0���ϱ� 1���� 2���ϱ� : ");
	scanf("%d", &ch);
	if (ch >= 0 && ch <= 2) {
		c.DoCalc(arop[ch], a, b);
	}
	/*switch (ch)
	{
	case 0:
		c.Op1(a, b);
		break;
	case 1:
		c.Op2(a, b);
		break;
	case 2:
		c.Op3(a, b);
		break;
	}*/
	return 0;
}