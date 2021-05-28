//#include <stdio.h>
//
//int main() {
//	int* ar;
//	ar = new int[5];	//(int*)malloc(sizeof(int)*5)==>C에서 사용할 때 배열명을 써주면 안되나? 안되겠지 이 형식으로 알아두자
//	for (int i = 0; i < 5; i++) {
//		ar[i] = i;
//	}
//	for (int i = 0; i < 5; i++) {
//		printf("%d번째=%d\n", i,ar[i]);
//	}
//	delete[]ar;
//	return 0;
//}