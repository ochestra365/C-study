//#include <stdio.h>
//
//void divide(int a, int d) {
//	if (d == 0)throw "0으로는 나눌 수 없습니다.";//중간에 점프가 되었다. 에러 발생구간에서 점프해서 넘어간다.반납이 안되었따. 스택 되감기를 통해 스택 프레임을 정리한다.
//	printf("나누기 결과 = %d\n", a / d);
//}//몸체의 끝을 만나야 스택이 반환된다.
//
//int main() {
//	//divide(2, 0);
//	try {
//		divide(2, 0);
//	}
//	catch (const char* message) {
//		puts(message);
//	}
//	divide(10, 5);
//	return 0;
//}