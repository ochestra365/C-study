#include <stdio.h>//표준 입출력 버퍼 전처리
#include <string.h>//문자 특화함수 전처리

class Human {//객체 선언
private://보안
	char* pname;//동적 할당 필드
	int age;//필드

public:
	Human(const char* aname, int aage) {//인수 2개 생성자, 이름은 상수(죽을때까지), 나이는 변함(가변적)
		pname = new char[strlen(aname) + 1];//부여받은 공간할당(null값 마침표 포함)
		strcpy(pname, aname);//모든 버퍼를 긁어다 복사해서 보안 레이블로 올림
		age = aage;//필드 복사
	}
	Human(const Human& other) {//깊은 복사 레퍼런스 사용 완전히 같은 하나의 객체 생성(목적): 파괴시 논리적 결함 제거
		pname = new char[strlen(other.pname) + 1];//부여 공간 할당(null)
		strcpy(pname, other.pname);//완전복사 버퍼 긁어다 복사
		age = other.age;//완전보갓 버퍼 긁어다 복사
	}
	~Human() {//파괴~는 컴파일러가 해당 로직에 빠른 접근을 도와준다.
		delete[]pname;//배열요소 파괴
	}
	void intro() {//기능
		printf("%s %d", pname, age);
	}
};
void printHuman(Human who) {//객체 인수로 받아서 출력
	who.intro();//객체에 대한 기능 
}
int main() {//메인
	Human k("k", 1);//생성
	Human b = k;//복사
	printHuman(b);//기능
}
//DB 연결이나 네트워크 연결 등 독점적인 자원이 필요한 클래스는 복사 생성자 정의(포트는 하나)