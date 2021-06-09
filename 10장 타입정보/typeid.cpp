//#include <stdio.h>
//#include <typeinfo>
//
//class Parent {
//public:
//	virtual void PrintMe() { printf("I am Parent\n"); }
//};
//class Child :public Parent {
//private:
//	int num;
//public:
//	Child(int anum):num(anum){}
//	virtual void PrintMe() { printf("I am Child\n"); }
//	void PrintNum() { printf("Hello Child=%d\n", num); }
//};
//void func(){}
//int main() {
//	Parent P, * pP;
//	Child C(123), * pC;
//	pP = &P;
//	pC = &C;
//	int val;
//	printf("P=%s, pP=%s, *pP=%s\n", typeid(P).name(), typeid(pP).name(), typeid(*pP).name());
//	printf("C=%s, pC=%s, *pC=%s\n", typeid(C).name(), typeid(pC).name(), typeid(*pC).name());
//
//	pP = &C;//부모클래스 타입의 포인터가 자식객체를 가리키게 하고 있다.-->부모는 자식을 가리킬 수 있다.
//	//접근해서 가져오는 것은 Child이다. 실질적인 객체가 중요하기 때문에 객체 타입에 맞는 메서드를 호출하기 위해서는  virtual로 메서드를 선언하는 것이 중요하다.
//	printf("pP=%s, *pP=%s\n", typeid(pP).name(), typeid(*pP).name());
//	printf("func = %s\n", typeid(func).name());
//	return 0;
//}