#include <stdio.h>

void divide(int a, int d) 
try {
	if (d == 0)throw "0���� �� ������.";
	printf("������ ��� = %d\n", a / d);
}

catch (const char* message) {//try ������throw ó���� catch���� ����ó������ ���ڷ� �ѱ��.
	puts(message);
}
int main() {
	divide(10, 0);
}