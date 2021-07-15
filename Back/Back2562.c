//#define _crt_secure_no_warnings
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//
//
//int main() {
//	int ary[9];
//	int size = sizeof(ary) / sizeof(ary[0]);
//	int* pary = (int*)malloc(sizeof(ary));
//	int j;
//	for (int i = 0; i < size; i++) {
//		scanf("%d", &pary[i]);
//	}
//	int max = pary[0];
//	for (j = 0; j < size; j++) {
//		if ((max < 0) && (max > 100)) {
//			if (max < pary[j + 1]) max = pary[j + 1];
//		}
//		else {
//			break;
//		}
//	}
//	printf("%d\n", max);
//	for (int k = 0; k < size; k++) {
//		if ((max < 0) && (max > 100)) {
//			if (max == pary[k]) printf("%d", k + 1);
//		}
//		else {
//			break;
//		}
//	}
//	return 0;
//}