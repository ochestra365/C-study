#include <stdio.h>
int count = 0;//정적 변수 외부선언
class Simple {
private:
	int value;//이거 왜있음?
public:
	Simple() { count++; }//객체 생성시 숫자가 카운팅 된다.
	~Simple() { count--; }//객체 파괴시 숫자가 마이너스 된다.
	void Outcount() {
		printf("%d\n", count);
	}
};

int main() {
	Simple s, * ps;//객체와 포인터 생성
	s.Outcount();//객체에 대한 멤버 함수 실행
	ps = new Simple;//새로운 클래스 할당
	ps->Outcount();//숫자 만들어짐
	delete ps;//파괴
	s.Outcount();//
	printf("%d\n", sizeof(s));

	return 0;
}