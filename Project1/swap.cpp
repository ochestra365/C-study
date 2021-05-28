#include <stdio.h>
void swap(int& ra, int& rb);
int main() {
	int a = 3, b=4;
	swap(a, b);
	printf("%d\n%d", a, b);
}
void swap(int& ra, int& rb) {
	int temp;

	temp = ra;
	ra = rb;
	rb = temp;
}