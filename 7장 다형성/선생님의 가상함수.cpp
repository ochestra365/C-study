//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	void AFunc() {
//		cout << "A::AFunc()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void BFunc() {
//		cout << "B::BFunc()" << endl;
//	}
//};
//class C : public B {
//public:
//	void CFunc() {
//		cout << "C::CFunc()" << endl;
//	}
//};
//int main()
//{
//	A* pa = new C;// 기초클래스 타입의 포인터가 파생객체를 가리키고 있다.
//	pa->AFunc();
//	B* pb = new C;
//	pb->AFunc();
//	pb->BFunc();
//	C* pc = new C;
//	pc->AFunc();
//	pc->BFunc();
//	pc->CFunc();
//	return 0;
//}
//
////힙영역에 A클래스 타입의 크기가 만들어지면서 A타입을 가리키고 있다. C타입으로 메모리 동적할당을 받으면서 자료형 자체가 다르게 된다.