#include <stdio.h>

class Simple {
private:
	int value;
	static int count;

public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {//초기값 정적 변수 선언 함수
		count = 0;//카운트 제로
	}
	static void OutCount() {
		printf("%d\n", count);
	}
};
int Simple::count;//모든 객체가 해당 멤버를 공유함. 소속만 밝혀주면 됨

int main() {
	Simple::InitCount();//카운트 0
	Simple::OutCount();
	Simple s, * ps;//카운트 1
	Simple::OutCount();
	ps = new Simple;//카운트 2
	Simple::OutCount();
	delete ps;//카운트 1
	Simple::OutCount();
	printf("%d\n", sizeof(s));
}//카운트 0