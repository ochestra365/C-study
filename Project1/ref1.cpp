//#include<stdio.h>
//
//int main() {
//	int i = 3;
//	int& ri = i;
//	int* pi=&i;
//	printf("i=%d, ri=%d\n", i, ri);
//	ri++;
//	printf("i=%d,ri%d\n", i, ri);
//	*pi = i + 1;
//	printf("i=%d,ri%d\n", i, ri);//레퍼런스와 변수값 모두 1씩 증가한다.
//	printf("i번지 =%x,ri 번지=%x\n", &i, &ri);//같은 주소 공유
//
//}