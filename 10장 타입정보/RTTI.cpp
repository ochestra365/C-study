//#include <stdio.h>
//
//class Parent {
//public:
//	virtual void PrintMe() { printf("I am Parent\n"); }//������� ������ ��ü�� �ڷ����� ������.
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
//void func(Parent* p) {//�θ� Ÿ���̶� ����ȯ�� �Ͼ��.
//	p->PrintMe();
//	((Child*)p)->PrintNum();//�θ����·� ����ȯ �� ���� �ڽ� ���·� ���� ����ȯ�� ����Ŵ-->�θ� ��ü�� ����Ʈ ���� ����. �׷��� �̻��� ������ ���� ��µȴ�.
//	//�ڽ� ��ü�� �����Ͱ� �ڽİ�ü�� ����Ų��.
//}
//
//int main() {
//	Parent p;
//	Child c(5);
//
//	func(&c);
//	func(&p);
//}