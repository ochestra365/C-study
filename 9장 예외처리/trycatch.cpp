//#include <stdio.h>
//
//int main() {
//	int a, b;
//	try {
//		printf("�������� ���� �Է��ϼ��� : ");
//		scanf_s("%d", &a);
//		if (a < 0)throw a;
//		printf("������ ���� �Է��ϼ��� : ");
//		scanf_s("%d", &b);
//		if (b == 0)throw"0���� ���� �� �����ϴ�.";
//		printf("������ ����� %d�Դϴ�.\n", a / b);
//	}
//	catch (int a) {
//		printf("%d�� �����̹Ƿ� ������ �ź�\n", a);
//	}
//	catch (const char* message) {
//		puts(message);
//	}
//	return 0;
//}