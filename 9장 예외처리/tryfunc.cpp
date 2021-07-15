#include <stdio.h>

void divide(int a, int d) 
try {
	if (d == 0)throw "0으로 못 나눈다.";
	printf("나누기 결과 = %d\n", a / d);
}

catch (const char* message) {//try 구문의throw 처리를 catch에서 예외처리항의 인자로 넘긴다.
	puts(message);
}
int main() {
	divide(10, 0);
}