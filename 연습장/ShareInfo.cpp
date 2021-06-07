#include <stdio.h>

class Exchange {
private:
	static double rate;//���� ������� �ʵ�

public:
	static double GetRate() { return rate; }//������ ��ȯ
	static void SetRate(double aRate) { rate = aRate; }//��º�ȯ �� ��ȯ
	double DollarToWon(double d) { return d * rate; }//ġȯ
	double WonToDollar(double w) { return w / rate; }//ġȯ
};

double Exchange::rate;//������-->�������� ��������� �����ϴ� ���� �� ���� �д�.
int main() {
	Exchange::SetRate(1200);//�ʱ� ȯ��
	Exchange A, B;//A,B�� ��ġ
	printf("1�޷��� %.0f���̴�.\n", A.DollarToWon(1.0));
	Exchange::SetRate(1150);//ȯ�� ����
	printf("1�޷��� %.0���̴�.\n", B.DollarToWon(1.0));
}