#include <stdio.h>

class Simple {//클래스 선언
private:
	int value;//멤버변수
	static int count;//클래스에서 정적으로 조작됨
public:
	Simple() { count++; }//객체가 만들어지면 카운트를 늘린다.
	~Simple() { count--; }//객체가 파괴도면 카운트를 줄인다.
	static void InitCount() {//초기의 카운트는 0
		count = 0;
	}
	static void OutCount() {//현재 객체의 카운트 수를 가져온다.
		printf("현재 객체 개수= %d\n", count);
	}
};

int Simple::count;//카운트는 정적함수이기 떄문에 외부에서 초기화한다.
int main() {
	Simple::InitCount();
	Simple::OutCount();
	Simple s, * ps;
	Simple::OutCount();
	ps = new Simple;
	Simple::OutCount();
	delete ps;
	Simple::OutCount();
	printf("크기 = %d\n", sizeof(s));
}