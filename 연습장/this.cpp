#include <stdio.h>
class Simple {
private:
	int value;
public:
	Simple(int avalue): value(avalue){}//������ �ʱ�ȭ->�����ڴ� �ش� ������ �ʱ�ȭ�ȴ�.
	void OutValue() {
		printf("%d", value);
	}
};

int main() {
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
}