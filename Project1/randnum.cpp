//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "cursor.h"
//
//class RandNum {
//private:
//	int num;
//
//public:
//	RandNum() { randomize(); }
//	void Generate() { num = random(100) + 1; }
//	bool Compare(int input) {
//		if (input == num) {
//			printf("OK\n");
//			return true;
//		}
//		else if (input > num) {
//			printf("small\n");
//		}
//		else {
//			printf("big\n");
//		}
//		return false;
//	}
//};
//class Ask {
//private:
//	int input;
//
//public:
//	void Prompt() { printf("\n���� ���� ����\n"); }
//	bool AskUser() {
//		printf("���� �Է�(���� 999) : ");
//		scanf("%d", &input);
//		if (input == 999) {
//			return true;
//		}
//		return false;
//	}
//	int GetInput() { return input; }
//};
//
//int main() {
//	RandNum R;
//	Ask A;
//
//	for (;;) {
//		R.Generate();
//		A.Prompt();
//		for (;;) {
//			if (A.AskUser()) {
//				exit(0);
//			}
//			if (R.Compare(A.GetInput())) {
//				break;
//			}
//		}
//	}
//}