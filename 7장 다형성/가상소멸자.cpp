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
//		cout << num << " CTest�ı�"<<endl;
//	}
//	void func() {
//		cout << "CTest function()" << endl;
//	}
//};
//class CTestSub : public CTest {
//private:
//	int subN;
//public:
//	CTestSub(int num,int asubN):CTest(num){//��� ������ �ݷ� �ʱ�ȭ�� �Ѵ�.
//		subN = asubN;
//		cout << subN << "CTestSub constructor" << endl;
//	}
//	~CTestSub() {
//		cout << subN << "CTestSub �ı�" << endl;
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
//	CTest* pb = new CTestSub(30,33);//���� �Ҵ� �����ڸ� ���� ���긦 ����� �ִ�. 33�� �ش��ϴ� �ı��ڰ� ����.
//	pb->func();
//	delete pb;//�޸� ����
//	//�޸� �����Ҵ�ÿ� �ı��ڰ� ȣ���� ���� �ʴ´�.
//	//���� �Ҵ�� �ı��ڵ� ���� �Ҹ��� ���·� ���ָ� �Ϻ��ϰ� �����Ǿ��� ��� ��ü���� �Ҹ�ȴ�.
//	return 0;
//}