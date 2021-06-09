//#include <stdio.h>
//
//class Parent {
//public:
//	virtual void PrintMe() { printf("I am Parent\n"); }//버츄얼이 있으면 객체의 자료형을 따른다.
//};
//class Child :public Parent {
//private:
//	int num;
//public:
//	Child(int anum) : num(anum) {}
//	virtual void PrintMe() {
//		printf("I am Child\n");
//	}
//	void PrintNum() { printf("Hello Child =  %d\n", num); }
//};
//void func(Parent* p) {//부모 타입이라 형변환이 일어난다.
//	p->PrintMe();
//	((Child*)p)->PrintNum();//부모형태로 형변환 된 것을 자식 형태로 강제 형변환을 일으킴-->부모 객체는 프린트 넘이 없다. 그래서 이상한 쓰레기 값이 출력된다.
//	//자식 객체의 포인터가 자식객체를 가리킨다.
//}
//
//int main() {
//	Parent p;
//	Child c(5);
//
//	func(&c);
//	func(&p);
//}