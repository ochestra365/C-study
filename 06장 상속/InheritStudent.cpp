//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//class Human {
//private:
//	char name[12];
//	int age;
//public:
//	Human(const char* aname, int aage) {
//		strcpy(name, aname);
//		age = aage;
//	}
//	void intro() {
//		printf("이름 = %s, 나이 = %d\n", name, age);
//	}
//};
//
//class Student : public Human {
//private:
//	int stunum;
//public:
//	Student(const char* aname, int aage, int astunum) :Human(aname, aage) {//부모의 멤버도 자식클래스에서 다 물려받기 때문에 인수로 취급한다. 콜론 초기화가 되어 있다. 부모 클래스의 디폴트 생성자
//		stunum = astunum;
//	}
//	void study() {
//		printf("이이는 사, 이삼은 육, 이사 팔\n");
//	}
//};
//int main() {
//	Human kim("김상형", 29);//휴먼이라는 부모클래스 타입의 객체가 생성됨.
//	kim.intro();
//	Student han("김한결", 15, 12345);//그리고 그 객체의 성질을 상속받아서 자식클래스가 만들어짐.
//	han.intro();//휴먼이라는 클래스를 퍼블릭 타입으로 상속을 받았기 때문에 쓸 수가 있다. 자유롭게
//	han.study();
//	return 0;
//}