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
//	virtual void test() { printf("B::test()\n"); }//virtual Ű���尡 �����־ virtual�� ǥ��ȴ�.
//	void test2() { printf("B::test()\n"); }
//};
//class C :public B {
//public:
//	void test() { printf("C::test()\n"); }
//	void test2() { printf("C::test()\n"); }
//};
//void GlobalFunc(A& a) {
//	try {
//		C& c = dynamic_cast<C&>(a);//�θ� �ڽ��� ����Ų��.
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
//	C* pc = dynamic_cast<C*>(paa);//����ȯ�� �̷�������� ���ϴ� ����� ���� �� ����. upcasting�̴�.
//	//�ϱػ��� �Ͼ�� �ȵȴ�. �ڽ��� �θ� ����Ű�� �ִ�. ĳ������ �Ͼ�� ������ ���ϴ� ����� ���� �� ����.
//	//�ڽ������ͷ� �θ� ��ü�� ����Ű�� �����̴�. ���� �ҿ����� ĳ�����̴�. downcasting
//	if (pc)pc->test2();
//
//	C c;
//	GlobalFunc(c);//������ ����Ű�� �ִ� �Լ�
//	B b;
//	GlobalFunc(b);//b�� �ڽ��� c��� �����ͷ� ����Ű�� �־ ���ܰ� �߻���.
//	return 0;
//}
////�ڽ��� �θ� ��ü�� ����ų ���� ����. �θ� �ڽİ�ü�� ����ų �� �ִ�. �ϱػ��� �Ͼ�� �ȵȴ�. �� �ܴ� ���� ������ �߻��Ѵ�.