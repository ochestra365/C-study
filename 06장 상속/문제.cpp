#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Student {
private:
	char* name;
	char* major;
public:
	Student(const char* aname,const char *amajor) {
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
		int len2 = strlen(amajor) + 1;
		major = new char[len2];
		strcpy_s(major, len2, amajor);
	}
	~Student() {
		delete[] name, major;
	}
	
};
class INTRO : public Student {
protected:
	char me[32];
	char name[32];
public:
	INTRO(const char* aname, const char* amajor) :Student(aname, amajor) {
		strcpy(name, aname);
		strcpy(me, amajor);
	}
	void print() {
		cout << "My name is" << name << "My major is " << me << endl;
	}
};

int main() {
	INTRO my("¹Ú¼ºÃ¶", "IOT");
	my.print();
	return 0;
}