//#include <stdio.h>
//
//class Base {// ���̽� ����
//private:
//	char* B_buf;//������ �޸𸮵����Ҵ�ÿ� virtual�� ���ش�.
//public:
//	Base() { B_buf = new char[10]; puts("Base ����"); }//������ �����ʹ� 10���� ���۸� ��´�. �׸��� ���
//	virtual ~Base() { delete[] B_buf; puts("Base�ı�"); }//�޸� �����Ҵ� ������ ���̽����� �����ı��ڸ� ���ش�. 
//	//���߾� ���̺��� ����Ѵ�.
//};
//
//class Derived : public Base {//���
//private:
//	int* D_buf;//�����Ҵ�
//public:
//	Derived() {
//		D_buf = new int[32]; puts("Derived ����");//�� ���� �Ҵ�
//	}
//	virtual ~Derived() { delete[] D_buf; puts("Derived �ı�"); }//���� ���̺��� �̿��ؼ� �ı�
//};
//
//int main() {
//	Base* pB;
//
//	pB = new Derived;
//	delete pB;
//}