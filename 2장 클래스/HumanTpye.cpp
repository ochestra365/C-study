#include <stdio.h>
class Human {
public:
	char name[12];
	int age;
	//속성의 크기에 따라서 인스턴스의 크기가 정해진다.
	void intro() {//멤버함수는 포함이 되지 않는다. 코드영역에 저장되서 멤버함수를 각 인스턴스들이 공유한다.
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main() {
	Human arFriend[10] = {
		{"문동욱",49},//인스턴스 1 각각 객체는 dispoint를 가지고 있다.
		{"김유진",49},//인스턴스 2
		{"박상막",49}//인스턴스 3
	};
	//인스턴스의 크기는 각 필드의 크기 총합이다.
	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();//첫번째 인자로는 그 객체의 dispoint를 전달해주고, 함수에서 시행한다.
}