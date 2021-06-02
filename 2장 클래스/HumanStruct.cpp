#include <iostream>

struct Human {
public:
	char name[20];
	float height;
	float weight;
	int age;
	char blood;
	void view(); 
};
void Human::view() {//구조체는 멤버접근 지정자가 기본적으로 public으로 만들어져 있다.
	printf("나의 이름은 %s이고 이고 키는 %f이고 몸무게는 %f이고 나이는 %d이고 혈액형은 %c이다.", name, height, weight, age, blood);
}//클래스는 속성과 기능들이 들어가 있다. 구조체에서 멤버함수가 추가로 들어간 것이 클래스이다.
int main() {
	Human my = { "박성철",168,64,28,'b'};
	my.view();
	return 0;
}