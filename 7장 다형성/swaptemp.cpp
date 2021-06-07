//#include <stdio.h>
//
//template<typename T>//템플릿 설정 선언된 이후에 이것들이 적용되어야 한다.
//void swap(T& a, T& b) {//타입에 대한 정의
//	T t;
//	t = a; a = b; b = t;//변환 알고리즘
//}
//int main() {
//	int a = 3, b = 4;
//	double c = 1.2, d = 3.4;
//	char e = 'e', f = 'f';
//	swap(a, b);
//	swap(c, d);
//	swap(e, f);
//	printf("a = %d,b = %d\n", a, b);
//	printf("c = %f,d = %f\n", c, d);
//	printf("e = %c,f = %c\n", e, f);
//}