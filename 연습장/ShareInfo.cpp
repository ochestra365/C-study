#include <stdio.h>

class Exchange {
private:
	static double rate;//정적 멤버변수 필드

public:
	static double GetRate() { return rate; }//이자율 반환
	static void SetRate(double aRate) { rate = aRate; }//상승변환 후 반환
	double DollarToWon(double d) { return d * rate; }//치환
	double WonToDollar(double w) { return w / rate; }//치환
};

double Exchange::rate;//이자율-->공통으로 계속적으로 참조하는 것은 한 곳에 둔다.
int main() {
	Exchange::SetRate(1200);//초기 환율
	Exchange A, B;//A,B의 가치
	printf("1달러는 %.0f원이다.\n", A.DollarToWon(1.0));
	Exchange::SetRate(1150);//환율 변동
	printf("1달러는 %.0원이다.\n", B.DollarToWon(1.0));
}