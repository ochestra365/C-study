#include <stdio.h>//표준 입출력 버퍼 전처리

class Some {//객체 선언
public://공유
	const int total;//상수화
	Some(int atotal) :total(atotal) {}//멤버 초기화-->대입문으로 상수 변경 불가 특별 영역에서 초깃값 처리
	//시각적으로 상수를 변수처럼 쓰는 것처럼 보임
	void OutTotal() { printf("%d\n", total); }//기능
};

int main() {
	Some S(5);
	S.OutTotal();
}