#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

template<typename T>
void swap(T& a, T& b) {//Human 클래스다.(하나의 자료형이다.)
	T t;
	t = a; a = b; b = t;
}
class Human {
private:
	char* name;
	int age;
public:
	Human() {//생성자
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}
	Human(const char* aname, int aage) {//2개의 인수를 가진 생성자
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}
	Human(const Human& other) {//복사생성자(참조형식으로 매개변수로 들어간 것이 복사생성자이다.)==>변환생성자 인수 하나는 변환생성자
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	Human& operator = (const Human& other) {//연산자 오버로딩
		if (this != &other) {
			delete[]name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}
	~Human() {//파괴자<-->소멸자
		delete[]name;
	}
	void intro() {//멤버함수
		printf("이름 = %s, 나이 =%d\n", name, age);
	}
};

int main() {
	Human lee("이승만", 10);
	Human park("박정희", 20);
	lee.intro();
	park.intro();
	swap(lee, park);
	lee.intro();
	park.intro();
}