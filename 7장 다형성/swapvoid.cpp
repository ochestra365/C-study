#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void swap(void* a, void* b, size_t len) {//메모리의 사이즈를 측정해서 복사한다.
	void* t = nullptr;//초기화
	t = malloc(len);//길이를 재준다. 길이도 객체로 정해서 측정이 자동으로 되게함.
	memcpy(t, a, len);
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main() {
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(&a, &b, sizeof(int));
	swap(&c, &d, sizeof(double));
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f,d = %f\n", c, d);
}
