//#include <stdio.h>
//
//class Base {// 베이스 생성
//private:
//	char* B_buf;//포인터 메모리동적할당시에 virtual을 써준다.
//public:
//	Base() { B_buf = new char[10]; puts("Base 생성"); }//생성자 포인터는 10개의 버퍼를 담는다. 그리고 출력
//	virtual ~Base() { delete[] B_buf; puts("Base파괴"); }//메모리 동적할당 해제시 베이스에서 가상파괴자를 써준다. 
//	//버추얼 테이블을 사용한다.
//};
//
//class Derived : public Base {//상속
//private:
//	int* D_buf;//동적할당
//public:
//	Derived() {
//		D_buf = new int[32]; puts("Derived 생성");//더 많이 할당
//	}
//	virtual ~Derived() { delete[] D_buf; puts("Derived 파괴"); }//가상 테이블을 이용해서 파괴
//};
//
//int main() {
//	Base* pB;
//
//	pB = new Derived;
//	delete pB;
//}