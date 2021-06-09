//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class A {
//public:
//	virtual void test() { printf("A::test()\n"); }
//};
//class B : public A {
//public:
//	virtual void test() { printf("B::test()\n"); }//virtual 키워드가 빠져있어도 virtual로 표기된다.
//	void test2() { printf("B::test()\n"); }
//};
//class C :public B {
//public:
//	void test() { printf("C::test()\n"); }
//	void test2() { printf("C::test()\n"); }
//};
//void GlobalFunc(A& a) {
//	try {
//		C& c = dynamic_cast<C&>(a);//부모를 자식이 가리킨다.
//		printf("GlobalFunc()\n");
//	}
//	catch(bad_cast){
//		printf("casting error");
//	}
//}
//int main() {
//	A* pa = new C;
//	A* paa = new B;
//	pa->test();
//	B* pb = dynamic_cast<B*>(pa);
//	if (pb)pb->test2();
//	C* pc = dynamic_cast<C*>(paa);//형변환은 이루어지지만 원하는 결과는 얻을 수 없다. upcasting이다.
//	//하극상이 일어나면 안된다. 자식이 부모를 가리키고 있다. 캐스팅이 일어나고 있지만 원하는 결과를 얻을 수 없다.
//	//자식포인터로 부모 객체를 가리키는 형태이다. 따라서 불완전한 캐스팅이다. downcasting
//	if (pc)pc->test2();
//
//	C c;
//	GlobalFunc(c);//본인을 가리키고 있는 함수
//	B b;
//	GlobalFunc(b);//b의 자식인 c라는 포인터로 가리키고 있어서 예외가 발생함.
//	return 0;
//}
////자식이 부모 객체를 가리킬 수는 없다. 부모가 자식객체를 가리킬 수 있다. 하극상이 일어나면 안된다. 그 외는 전부 에러가 발생한다.