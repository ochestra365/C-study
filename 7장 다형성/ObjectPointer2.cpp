//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//class Human {
//protected:
//	char name[12];
//	int age;
//
//public:
//	Human(const char* aname, int aage) {
//		strcpy(name, aname);
//		age = aage;
//	}
//	virtual void intro() {
//		printf("이름 = %s, 나이=%d\n", name, age);
//	}
//};
//class Student : public Human {
//protected:
//	int stunum;
//public:
//	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {//선생님이 내주신 문제의 답안
//		stunum = astunum;
//	}
//	void intro() {// 상속된 자식클래스도 virtual로 만들어진다. 자식 클래스가 부모 클래스를 가리킬 수 있게 한다.
//		//다만 명시적 의미로 virtual을 붙여준다.
//		printf("%d학번 %s입니다. \n", stunum, name);
//	}
//	void study() {
//		printf("이이는 사, 이삼은 육, 이사 팔\n");
//	}
//};
//
//int main() {
//	Human h("김사람", 10);
//	Student s("이학생", 15, 1234567);
//	Human* pH;
//	Student* pS;
//	pH = &h;//당연히 가능-->포인터 자료형과 객체 자료형이 동일하다.
//	pS = &s;//당연히 가능-->포인터 자료형과 객체 자료형이 동일하다.
//	pH = &s;//가능--> Human 자료형 , Student 자료형이 다르다. 부모 자료형이라서 자식을 가리킬 수 있다. upcasting
//	//pS=&h;//에러
//	pS = (Student*)&h;//ps 자료형은 Student다. Human은 h 자식이 부모를 가리키는 것이다.(다운캐스팅)-->형변환
//	pS->intro();
//}