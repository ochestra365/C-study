#include <stdio.h>//전처리기에서 표준입출력 버퍼 호출
#include <string.h>//문자특화함수 사용

class Human {//객체
private://보안
	char name[12];//필드
	int age;//필드

public:
	Human() {//생성자->초기화
		strcpy(name, "이름없음");//초기화
		age = 0;//초기화
	}
	void intro() {//기능
		printf("이름 = %s, 나이 =%d", name, age);
	}
};

int main() {//메인

	Human momo;//객체 생성
	momo.intro();//기능 구현
}