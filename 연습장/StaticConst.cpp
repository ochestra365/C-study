#include <stdio.h>

class MathCalc {
private:
	static const double pie;
public:
	MathCalc(){}
	void DoCalc(double r) {
		printf("%.2f %.2f", r, r * 2 * pie);
	}
};
const double MathCalc::pie = 3.1416;

int main() {
	MathCalc m;
	m.DoCalc(5);
}