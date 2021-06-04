#include <stdio.h>//표준입출력 버퍼 전처리기 처리
#include <string.h>//문자특화함수 처리

class Human {//객체생성
private://보안
	char name[12];//필드
	int age;//필드

public://공유
	Human(const char* aname, int aage) {//생성자 이름은 상수 나이는 변함
		strcpy(name, aname);//메인에서 변수를 복사해서 필드에 저장
		age = aage;//메인에서 변수를 복사해서 필드에 저장
	}
	void intro() {//기능
		printf("%s %d", name, age);
	}
};

int main() {//메인의 메모리
	//Human momo;//에러
	//Human arFriend[3];//개발자가 반드시 시그니처를 주도록 규칙을 정함
	Human arFriend[3] = {//클래스 배열, 물리적 일련의 시퀀스
		{Human("문동욱",40)},//객체
		{Human("김유진",40)},//객체
		{Human("박상막",40)}, //객체
	};
	arFriend[2].intro();//두번쨰 배열요소의 기능 실현
}

//Human(const char *aname="", int aage=0); // 디폴트 