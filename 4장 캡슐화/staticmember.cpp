//#include <iostream>
//
//class StaticTest {//Ŭ������ ������Ʋ ���� �Ű�, ��ü�� ������ Ʋ���� ��������� Į���� �Ŵ�.
//	static int a;//static �������
//	int b;
//public:
//	StaticTest();
//	static void setData(int);//static�̶�� ����Լ��� static ��������� ����Ѵ�.
//	void getData();
//};
//int StaticTest::a = 10;	//static ������� �ʱ�ȭ
//StaticTest::StaticTest() {//���ԵǾ� �ִٴ� ���̴�.
//	this->b = 20;//��Ģ�� �� ������ �´�. �Ϲ����� ��������� �� ������ ������.
//}
//void StaticTest::getData() {
//	printf("a : %d,b : %d\n", a,b);
//}
//void StaticTest::setData(int aa) {
//	//this->a=aa; //this �����͸� ����� �� ����(�� ��ü�� ���Ե��� �ʴ´�.) ��ü�� ���� �ƴ϶� Ŭ������ ���̴�.
//	a = aa;//��ü�� ���� �ƴϱ� ������ this->�� �� �� ����. static�� �������� Ŭ������ �޶�پ� �ִ� ���̴�. ������ ���� �����ϴ� ���̴�.
//}
//int main() 
//{
//	StaticTest s1;
//	s1.getData();
//	StaticTest s2;
//	s2.getData();
//
//	s1.setData(30);
//	s1.getData();
//	s2.getData();
//
//	StaticTest::setData(40);//������ Ʋ�� �ƿ� �ٲ�����ϱ� ��� ��ü�� ������ �޴� ���̴�.
//	//Ŭ���� �Ҽ����� Ŭ������ ȣ���� �����ϴ�.
//	s1.getData();
//	s2.getData();
//	return 0;
//}