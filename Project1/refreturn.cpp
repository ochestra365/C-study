#include <stdio.h>

int ar[] = { 1,2,3,4,5 };
int& GetAr(int i) {
	return ar[i] ;
}
int main() {
	//int& ra = 10;--> 상수값은 레퍼런스가 올 수 없다.
	GetAr(3) = 6;
	printf("ar[3] =%d\n", ar[3]);
	return 0;
}