#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Human {
private:
	char* name;
public:
	Human(const char* aname) {
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
	}
	~Human() {
		delete[] name;
	}
	void printname() {
		cout << "My name is " << name << endl;
	}
};
class Student : public Human {
private://??
	char name[32];
	char* major;
public:
	Student(const char* amajor) {
		int len = strlen(amajor) + 1;
		major = new char[len];
		strcpy_s(major, len, amajor);
	}
	~Student() {
		delete[] major;
	}

	void PrintMajor() {
		cout << "My name is" << name << "My major is " << major << endl;
	}
};
int main() {
	Human my("박성철");
	my.printname();
	Student s("이름", "Iot");
	s.PrintMajor();
	return 0;
}
//못풀겠다.