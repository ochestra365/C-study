#include <stdio.h>

class Parent {};
class Child:public Parent{};
int main() {
	Parent P, * pP;//포인터끼리 연산과 변환은 불가능 하다.
	Child C, * pC;
	int i = 1234;
	//컴파일이 제공하는 기본 자료형의 변환이 아니라면 안된다.
	pP = static_cast<Parent*>(&C);//가능-->자식형태의 주소를 부모 형태로 바꾼다.
	pC = static_cast<Child*>(&P);//가능하지만 위험
	//pP = static_cast<Parent*>(&i);//불가
	//pC = static_cast<Child*>(&i);//에러
}