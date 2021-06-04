#include <stdio.h>//전처리기 표준 입출력 버퍼
#include <string.h>// 문자 특화함수

class Human {//객체 선언
private://보안
	char* pname;//동적할당 필드
	int age;//필드
public:
	Human(const char* aname, int aage) {//인수 2개 생성자(초기화) 
		pname = new char[strlen(aname) + 1];//공간 형성 null위함 초기화는 new 사용된 메모리 일 수 있으므로 값을 휘발
		strcpy(pname, aname);//완전한 타입의 복사
		age = aage;//복사
	}
	~Human() {//소멸	
		delete[]pname;//날림
	}
	void intro() {//기능
		printf("%s %d", pname, age);
	}
};

int main() {//메인
	Human k("k", 12);
	Human b = k;
	b.intro();
}
//에러
//이름을 날렸는데 또 날려야 하니 ㅈ 되는 것이다. 논리적 결함 발생 얕은 복사다