#include <stdio.h>
#include <iostream>
using namespace std;

 class Base{
private:
	int data;
public:
	Base() {};
	~Base() {};
	void setData(int adata){data = adata;}
	int getData() { return data; }
};
class Derived : public Base {
public://���� �����ڸ� ������ ������ private�� �Ǿ� �������� �� ����.
	void setData(int adata) {
		if (adata > 0) { adata = 0; }
		Base::setData(adata);
	}
	 void printData() {
		cout << "printData() : "<<getData() << endl;
	}
};
int main() 
{
	Base* pb = new Derived;//�θ� �ڽ��� ����Ŵ ���� Ŭ������ setData�� ȣ���.
	Derived* pd = NULL;
	pb->setData(10);
	pd = static_cast<Derived*>(pb);//static_cast
	pd->setData(20);//�Ļ�Ŭ������ setData()�� ȣ���.
	pd->printData();
	return 0;
}//�ڽ�Ŭ������ ���� ���� ������ ���� �ɾ ���ϴ� ����� �� �� �ְ� �Ѵ�.