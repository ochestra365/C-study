//#include <iostream>
//
//class statictest {
//public:
//	int a;
//	static int b;	// static ������� ����
//	statictest() {//������
//		a = 10;
//		//b = 20;	//Ŭ���� ���ο��� �ʱ�ȭ�� �ȵȴ�.
//		b++;
//	}
//	void getdata() {
//		printf("a : %d, b : %d\n", a,b);
//	}
//};
//int statictest::b = 20;// �Ҽ��� �ݵ�� ǥ���� �־�� �Ѵ�. �ܺο��� ����� ���� �Ҽ��� �ʿ��ϴ�. ->��ü���� �������� �ʴ´�.
////static ��� ���� �ʱ�ȭ(�ܺο��� �ʱ�ȭ�Ѵ�.)
//int main() {
//	statictest s1;
//	s1.getdata();
//	statictest s2;
//	s2.getdata();
//	
//	return 0;
//}