#include <stdio.h>

class Simple {
private:
	int value;
public:
	Simple(int avalue):value(avalue){}
	void OutValue() {
		printf("value=%d\n", value);
	}
};
int main() {
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
}
//�ڵ念���� ����Լ��� �����ϰ� �ִ� ���� ��ü���� �����ϸ鼭 this��� �����͸� ���ؼ� ����Լ��� �����Ѵ�.
//this �μ��� �Լ��� ȣ���� ��ü�� �������̸� ����� �����ϴ� ��� ���忡 this->�� �Ͻ������� ����ȴ�.
