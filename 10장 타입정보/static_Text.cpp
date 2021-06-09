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
public://접근 제한자를 써주지 않으면 private이 되어 엑세스할 수 없다.
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
	Base* pb = new Derived;//부모가 자식을 가리킴 기초 클래스의 setData가 호출됨.
	Derived* pd = NULL;
	pb->setData(10);
	pd = static_cast<Derived*>(pb);//static_cast
	pd->setData(20);//파생클래스의 setData()가 호출됨.
	pd->printData();
	return 0;
}//자식클래스일 수록 제한 조건을 많이 걸어서 원하는 기능을 걸 수 있게 한다.