#include <stdio.h>
class Simple {
private:
	int value;
public:
	Simple(int avalue): value(avalue){}//생성자 초기화->생성자는 해당 문제로 초기화된다.
	void OutValue() {
		printf("%d", value);
	}
};

int main() {
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
}