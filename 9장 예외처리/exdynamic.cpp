#include <stdio.h>

class SomeClass{};

void calc()throw(int) {
	SomeClass obj;
	char* p = new char[1000];
	if (true/*���ܹ߻�*/)throw 1;
	delete[]p;//���ܰ� �߻��ϸ� �����Ҵ�� �޸𸮰� ���� ���� �ʴ´�. ��, ����ؼ� �޸𸮴����� �߻��Ѵ�.
	puts("�޸� ����");
}

int main() {
	try {
		calc();
	}
	catch (int) {
		puts("������ ���� �߻�");
	}
}