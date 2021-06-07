#include <stdio.h>//디폴트
int GetSum(int from, int to, int step = 1, int base = 0);//항상 뒤에서 부터 디폴트 매개변수로 만들 수 있다.
int main() {
	printf("%d\n", GetSum(1, 10));
	printf("%d\n", GetSum(1, 10,2));
	printf("%d\n", GetSum(1, 10,2,10));
	return 0;
}

int GetSum(int from, int to, int step/*=1*/, int base/*=0*/) {
	int sum = base;
	for (int i = from; i <= to; i += step) {
		sum += i;
	}
	return sum;
}