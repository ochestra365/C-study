#include <stdio.h>//표준 입출력 버퍼를 전처리기로 추가한다.
#include <string.h>//문자계통 특화 함수를 전처리기로 추가한다.

class Human {//객체 만들기 객체 크기는 5
private://보안
	char* pname;//이름저장 필드
	int age;//나이 저장 필드
public://함수 공유
	Human(const char* aname, int aage) {//생성함. 인수 2개 
		pname = new char[strlen(aname) + 1];//배열로 널값 마지막으로 받을거 입력
		strcpy(pname, aname);//복사해서 필드에 저장
		age = aage;//복사해서 필드에 저장
		printf("%s 객체가 생성자 호출되었습니다.\n", pname);
	}
	~Human() {
		printf("%s 객체가 파괴되었습니다.\n", pname);
		delete[]pname;// 원하는 필드를 소멸시켜버림
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main() {
	Human boy("김수한무거북이와두루미", 12);//객체 호출ㅇ
	boy.intro();//객체 기능 구현
}
