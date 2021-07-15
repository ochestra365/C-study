#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Calc {
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void DoCalc(void(Calc::* fp)(int, int), int a, int b) {
		puts("����");
		printf("%d�� %d�� ���", a, b);
		(this->*fp)(a, b);
		puts("�̻�");
	}
};
int main() {
	int ch;
	Calc c;
	int a = 3, b = 4;
	void(Calc:: * arop[3])(int, int) = { &Calc::Op1,&Calc::Op2,&Calc::Op3 };

	printf("���� ��� 0,1,2");
	scanf("%d", &ch);
	if (ch >= 0 && ch <= 2) {
		c.DoCalc(arop[ch], a, b);
	}
	return 0;
}