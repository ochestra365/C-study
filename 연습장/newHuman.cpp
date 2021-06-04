#include <stdio.h>// 표준 입출력 장치를 전처리기에서 추가 시킴
#include <string.h>// 문자 특화 함수를 전처리기에서 추가 시킴

class Human {//객체 생성
private://보안
	char* pname;//필드
	int age;//필드
public://공유
	Human(const char* aname, int aage) {//생성자 인수-> const로 이름 지켜줌 동적할당, 
		pname = new char[strlen(aname) + 1];//필드에 널값을 포함한 문자
		strcpy(pname, aname);//실인수를 필드로 저장
		age = aage;//실인수를 필드로 저장
		printf("생성 %s", pname);//생성 확인 딱히 중요 x
	}
	~Human() {//소멸
		printf("객체 파괴 %s", pname);//파괴 확인
		delete[] pname;//배열로 확인
	}
	//위는 객체 관련, 아래는 기능 관련
	void intro() {
		printf("%s ,%d", pname, age);//기능확인
	}
};

int main() {
	Human boy("김수한", 12);
	boy.intro();

	Human* leo;//포인터
	leo = new Human("레오", 40);//new 연산자로 초기화이후 값을 대입
	leo->intro();//포인터는 기능을 가리킴
	delete leo;//포인터를 작살 내니까 객체를 가리킬 수단이 없음.
	return 0;
}