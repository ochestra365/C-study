#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class Calc {
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void DoCalc(void (Calc::* fp)(int, int), int a, int b) {//함수의 이름도 포인터다. 저장된 위치를 위치로 리턴시킴
		puts("연산결과");
		printf("%d와 %d의 연산결과", a, b);
		(this->*fp)(a, b);
		puts("이상");
	}
};

int main() {
	int ch;
	Calc c;
	int a = 3, b = 4;
	void(Calc:: * arop[3])(int, int) = { &Calc::Op1,&Calc::Op2,&Calc::Op3 };//포인터 배열
	puts("0더하기 1빼기 2곱하기 : ");
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