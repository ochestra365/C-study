#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

class CTest {
private:
	int m_num;

public:
	CTest() {
		printf("디폴트 생성자!\n");
	}
	CTest(int num) {//생성자는 초기화시켜주는 역할을 한다. 반대로 소멸자도 필요하다
		m_num = num;
		printf("생성자 호출 : %d\n", m_num);
	}
	void getData() {
		printf("%d\n", m_num);
	}
};
int main() 
{
	//기본 자료형
	int a = 10;
	int b(20);//새로운 형태의 변수 생성
	int c(a);
	printf("%d %d %d\n", a, b, c);
	//사용자 자료형
	CTest c1(100);//디폴트 생성자는 인수가 없다. 시행하기 위해서는 생성자를 하나 만들어 줘야 한다. 인수 1개의 생성자 호출
	CTest c2;//명시적으로 어떤 생성자를 만들게 되면 컴파일러에서 제공하는 디폴트 생성자를 쓸 수 가 없다.
	CTest c3(c1);//복사생성자 호출 (얕은 복사)
	c3.getData();
	printf("%d, %d\n", a,b);
	return 0;
}
/*
생성자 : 초기화
1. 디폴트
2. 복사생성자(1. 매겨변수, 2. return )
3. 변환생성자 : 인수가 1개
디폴트 생성자와 복사생성자는 자동으로 컴파일러가 생성해주는 것이다.
*/