#include <stdio.h>
#include <string.h>
int main() {
	int num;

	try {
		puts("1���� 100������ ������ �Է��Ͻÿ� : ");
		scanf_s("%d", &num);
		if (num < 1 || num>100)throw num;
		printf("�Է��� �� = %d\n", num);
	}
	catch (int num) {
		printf("%d�� 1���� 100������ ������ �ƴմϴ�.\n",num);
	}
}