#include <stdio.h>

void sub(int a) { printf("int : %d\n", a); }
void sub(int* a) { printf("pointer : %p\n", a); }

int main()
{
	int i = 1234, * pi = &i;
	sub(i);
	sub(pi);
	sub(NULL);//아무것도 가리키지 않는 포인터다. 3행 함수 호출 int형으로 취급하기 때문에 정수형이 출력되었다.
	//알고 있던 것과 차이가 많이 난다. 중복정의가 모호해진다. NULL은 정수값 0이다.
	//NULL도 강제 형변환이 필요하다. 잘못 쓰면 돌이킬 수 없는 결과를 초래할 수 있따.
}