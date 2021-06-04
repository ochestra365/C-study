#include <stdio.h>//표준 입출력 버퍼 전처리

class Some {//객체 생성
public://공유
	int& total;//레퍼런스
	Some(int &atotal):total(atotal){}//초기화 리스트 레퍼런스
	void OutTotal() { printf("%d", total); }
};
int main() {
	int v = 8;
	Some S(v);
	S.OutTotal();
}

//상수와 레퍼런스는 사용하기 전에 값과 대상이 정해져야 한다.