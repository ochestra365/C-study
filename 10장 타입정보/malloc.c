#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int ary[3];
	int* pary = (int*)malloc(sizeof(int));
	int size = sizeof(ary) / sizeof(ary[0]);
	for (int i = 0; i < size; i++) {
		scanf("%d", &pary[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("%d", pary[i]);
	}
	return 0;
}