//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void InputNameRef(char*& Name) {//실질적인 별명을 만들어서 직접 변수의 데이터 값을 핸들링하는 것이다.
//	Name = (char*)malloc(32);
//	strcpy(Name, "kim sang hyung");
//}
//int main() {
//	char* Name;
//
//	//InputNameRef(Name);// call by value, reference를 인지 알 수 없다.
//	//printf("이름은 %s", Name);
//	//free(Name);
//	//return 0;
//	int a = 10;
//	int& ra = a;
//	int* pa = &ra;
//	printf("%p %p %p", &a, &ra, pa);
//}