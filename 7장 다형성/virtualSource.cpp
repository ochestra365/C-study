//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//class Base 
//{
//public:
//	virtual void func1() {cout << "B:func1()" << endl;}
//	virtual void func2() { cout << "B:func2()" << endl; }
//	void func3() { cout << "B:func3()" << endl; }
//};
//class Derived : public Base {
//public:
//	void func1() { cout << "D:func1()" << endl; }//오버라이딩
//	void func3() { cout << "D:func3()" << endl; }
//	void func4() { cout << "D:func4()" << endl; }
//};
//int main() {
//	Base b;
//	Derived d;
//	Base* pb = new Derived;
//
//	pb->func1();//부모의 함수가 실행된다.
//	pb->func2();//실질적으로 함수가 없다.
//	pb->func3();//가상함수가 아닌 것들은 포인터 자료형을 따라간다.
//	return 0;
//}