#include <stdio.h>

class Simple {
private:
	int value;
public:
	Simple(int avalue):value(avalue){}
	void OutValue() {
		printf("value=%d\n", value);
	}
};
int main() {
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
}
//코드영역에 멤버함수가 존재하고 있는 것을 객체들이 존재하면서 this라는 포인터를 통해서 멤버함수에 접근한다.
//this 인수는 함수를 호출한 객체의 포인터이며 멤버를 참조하는 모든 문장에 this->가 암시적으로 적용된다.
