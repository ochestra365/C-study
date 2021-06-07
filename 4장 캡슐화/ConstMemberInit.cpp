#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Enemy {
private:
	const int Speed;
public:
	Enemy(int aSpeed):Speed(aSpeed){}//매개변수가 한 개인 생성자를 변환생성자라고 한다.
	void Move() {
		printf("%d의 속도로 움직인다.\n", Speed);
	}
};

int main() {
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}