#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

class CTest {
private://멤버변수 은닉
	int m_num;
	int* ptr;
public://멤버함수 공유 오버로딩을 이용해서 다수의 한 함수에 다수의 속성을 때려넣고 있다. 이게 마치 종합 카드 선물복지행사 비슷한 거다.
	CTest() {
		printf("디폴트 생성자!\n");
	}
	CTest(int num) {//생성자는 초기화시켜주는 역할을 한다. 반대로 소멸자도 필요하다
		m_num = num;
		printf("생성자 호출 : %d\n", m_num);
	}
	CTest(int num, int* ptr) {//새로운 메모리를 동적할당받고 객체 생성 초깃값을 메모리 동적할당 파트에 저장한다.
		this->m_num = num;
		this->ptr = new int;
		this->ptr = ptr;//메모리를 동적할당 시킴
		printf("복사생성자 호출");
	}
	CTest(CTest &other) {//입력은 참조형태의 클래스가 오게된다. 암기해야 한다. 복사생성자(매개변수, 복사하는 경우에 복사생성자, 리턴 객체를 생성하면 계속 재귀호출에 빠져버린다. 재귀호출을 막기위해 참조호출
		this->m_num = other.m_num;//arrow연산자
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
	CTest c3(c1);//복사생성자 호출 (얕은 복사)-주소를 복사.(참조를 전달 받기 때문이다.)
	CTest c4(50, nullptr);//널포인터 2개의 인수를 가지는 생성자가 없다.
	//레퍼런스는 변수명에 대한 별명이지만 사실은 포인터다. 
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
/*주소를 가져다 복사받으로 메모리 동적할당된 시작주소값을 받는다. 하나를 없애주면 없애주기 때문에 깊은 복사가 필요하다.
메모리 동적할당이 매우 중요하다. 임베디드 프로그램이기 때문이다. 기본 변수와 같이 생성하는 것이 가능하다.
*/

