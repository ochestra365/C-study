//#include <iostream>
//using namespace std;
//class CTest {
//public:
//	CTest() { cout << "CTest()" << endl; };
//	~CTest() { cout << "~CTest()" << endl; };
//	void func() { cout << "func()" << endl; }
//};
//int main() {
//	shared_ptr<CTest> ptr1(new CTest);//다수개의 메모리 동적할당을 할 수 있는부분
//	ptr1->func();
//	cout << "count : " << ptr1.use_count() << endl; {
//		shared_ptr<CTest>ptr2(ptr1);
//		cout << "count : " << ptr1.use_count() << endl;
//		ptr2->func();
//	}
//	cout << "count : " << ptr1.use_count() << endl;
//	//ptr2->func();//자동으로 메모리동적할당된 부분이 해제된다.
//	unique_ptr<CTest> ptr1(new CTest);//하나의 포인터만 가리킨다.
//	return 0;
//}