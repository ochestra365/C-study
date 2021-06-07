#include <stdio.h>

class Simple {
private:
	int value;
public:
	Simple(int avalue):value(avalue){}
	void OutValue() {
		printf("valude = %d\n", value);
	}
};
int main() {
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
}