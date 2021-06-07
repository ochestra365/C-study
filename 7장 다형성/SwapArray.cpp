//#include <stdio.h>//표준입출력 버퍼
//#include <malloc.h>//동적할당
//#include <memory.h>//메모리
//
//template<class T>//템플릿
//void swaparray(T* a, T* b, int num) {
//	void* t;
//
//	t = malloc(num * sizeof(T));//동적할당 아래는 스왑 알고리즘
//	memcpy(t, a, num * sizeof(T));
//	memcpy(a, b, num * sizeof(T));
//	memcpy(b, t, num * sizeof(T));
//	free(t);
//}
//
//int main() {
//	int a[] = { 1,2,3 }, b[] = { 4,5,6 };//배열
//	char c[] = "문자열", d[] = "string";//배열
//	swaparray(a, b, sizeof(a) / sizeof(a[0]));
//	printf("before c = %s, d = %s\n", c, d);
//	swaparray(c, d, sizeof(c) / sizeof(c[0]));
//	printf("after c= %s, d = %s\n", c, d);
//}