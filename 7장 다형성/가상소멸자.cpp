//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//class CTest {
//private:
//	int num;
//public:
//	CTest(int anum) {
//		num = anum;
//		cout << num << "CTest construct" << endl;
//	};
//	~CTest() {
//		cout << num << " CTest파괴"<<endl;
//	}
//	void func() {
//		cout << "CTest function()" << endl;
//	}
//};
//class CTestSub : public CTest {
//private:
//	int subN;
//public:
//	CTestSub(int num,int asubN):CTest(num){//상속 대상들은 콜론 초기화를 한다.
//		subN = asubN;
//		cout << subN << "CTestSub constructor" << endl;
//	}
//	~CTestSub() {
//		cout << subN << "CTestSub 파괴" << endl;
//	}
//	void func() {
//		cout << "CTestSub function()" << endl;
//	}
//};
//
//int main() {
//	CTest b(10);
//	b.func();
//	CTestSub d(10, 20);
//	d.func();
//	CTest* pb = new CTestSub(30,33);//동적 할당 연산자를 통해 서브를 만들고 있다. 33에 해당하는 파괴자가 없다.
//	pb->func();
//	delete pb;//메모리 해제
//	//메모리 동적할당시에 파괴자가 호출이 되지 않는다.
//	//동적 할당시 파괴자도 가상 소멸자 형태로 해주면 완벽하게 생성되었던 모든 객체들이 소멸된다.
//	return 0;
//}