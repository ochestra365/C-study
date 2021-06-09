#include <stdio.h>

class SomeClass{};

void calc()throw(int) {
	SomeClass obj;
	char* p = new char[1000];
	if (true/*예외발생*/)throw 1;
	delete[]p;//예외가 발생하면 동적할당된 메모리가 해제 되지 않는다. 즉, 계속해서 메모리누수가 발생한다.
	puts("메모리 해제");
}

int main() {
	try {
		calc();
	}
	catch (int) {
		puts("정수형 예외 발생");
	}
}