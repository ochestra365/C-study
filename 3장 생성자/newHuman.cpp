//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//class Human {
//private:
//	char* pname;
//	int age;
//
//public:
//	Human(const char* aname, int aage) {
//		pname = new char[strlen(aname) + 1];//널 문자를 위해서 1칸 여유칸을 준다.
//		strcpy(pname, aname);//복사받은 인수값을 객체의 값으로 복사해준다.
//		age = aage;
//		printf("==<%s>객체생성==\n", pname);
//	}
//	~Human() {//소멸자
//		printf("==<%s> 객체파괴==\n", pname);
//		delete[]pname;
//	}
//	void intro() {
//		printf("이름 %s, 나이 %d\n", pname, age);
//	}
//};
//
//int main() {
//	Human boy("김수한두루미와 거북이", 12);
//	boy.intro();
//	Human* leo;
//	leo = new Human("레오나르도 디카프리오", 40);//new 연산자로 쉽게 초기화가 가능하다.
//	leo->intro();
//	delete leo;//delete 연산자로 쉽게 객체 파괴가 가능하다.
//}