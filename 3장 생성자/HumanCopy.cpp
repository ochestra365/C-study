//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//class Human {
//private:
//	char* pname;
//	int age;
//public:
//	Human(const char* aname, int aage) {
//		pname = new char[strlen(aname) + 1];
//		strcpy(pname, aname);
//		age = aage;
//	}
//	~Human() {
//		delete[]pname;
//	}
//	void intro() {
//		printf("이름 : %s, 나이 = %d\n", pname, age);
//	}
//};
//int main()
//{
//	Human kang("강감찬", 1424);
//	Human boy = kang;//런타임 에러가 발생한다. 파괴한 객체를 또 파괴하려고 하니까 발생하는 현상이다.
//
//	boy.intro();
//}