//#include <stdio.h>
//template<typename T>//클래스 템플릿
//class Util {
//public:
//	void swap(T& a, T& b) {
//		T t;
//		t = a; a = b; b = t;
//	}
//};
//
//int main() {
//	Util <int> u;
//	Util<double> u1;
//	int a = 3, b = 4;
//	double c = 1.2, d = 3.4;
//	char e= 'e', f = 'f';
//	u.swap(a, b);
//	u1.swap(c, d);
//	//u.swap(e, f);
//	printf("a = %d, b = %d\n", a, b);
//	printf("c = %f, d = %f\n", c, d);
//	printf("e = %c, f = %c\n", e, f);
//	return 0;
//}