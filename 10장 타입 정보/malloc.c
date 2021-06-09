#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int ary[3];
	int* pary;
	int size = sizeof(ary) / sizeof(ary[0]);
	pary = (int*)malloc(sizeof(int) * size);//해제 공간을 모두 잡아 줘야 가능한 걱였따!!!
	//변수로써 그 공간을 제어 해주니 에러 없이 프로그램 실행이 되었다.!!!1
	for (int i = 0; i < size; i++) {
		scanf("%d", &pary[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("%d", pary[i]);
	}
	free(pary);
	return 0;
}