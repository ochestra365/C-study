#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class CMember {
private:
	char Name[12];
	int Phone;
	char Addr[100];
	static int cnt;

public://주요 로직 중 하나가 데이터를 세팅해서 클래스의 필드에 각각 저장하는 것이다.
	void setName(char* aName, int aPhone, char* aAddr, int acnt) {//배열은 넘겨받아서 필드로 올려준다.
		strcpy(this->Name, aName);
		Phone = aPhone;
		strcpy(this->Addr, aAddr);
		cnt++;
	}
	void getName() {//주요 로직 중 하나가 필드의 데이터에 저장된 값들을 불러오는 것이다.
		printf("\n>이름: %s\n>핸드폰 번호 : %d\n>주소 : %s\n>회원수: %d",Name,Phone,Addr,cnt);
	}
};
int CMember::cnt = 0;
int main() {
	CMember i;//어떠한 객체가 만들어진다.
	//어떠한 객체들의 정보들을 초기화해준다.
	char tempName[100] = "박성철";
	int tempPhone = 28741479;
	char tempAddr[100] = "제주특별자치도 제주시 월평10길 180 아라농장";
	int tempcnt=1;
	i.setName(tempName, tempPhone, tempAddr, tempcnt);
	i.getName();


	CMember j;// 이제는 쓰레기 값이 안 나오는데, static 어떻게 쓰는 건지 알아볼 필요가 있다.
	char jName[100] = "김두한";
	int jphone = 2929;
	char jAddr[100] = "서울 종로구 제 1구역";
	int jcnt = 2;
	j.setName(jName, jphone, jAddr, jcnt);
	j.getName();

	return 0;
}