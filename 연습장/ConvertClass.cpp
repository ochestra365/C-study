#include <stdio.h>
class Fahrenheit;//����
class Celsius {
public:
	double Tem;
	Celsius(){}//�ʱ�ȭ
	Celsius(double aTem):Tem(aTem){}//�ʱ�ȭ ����Ʈ
	operator Fahrenheit();//��ȯ
	void OutTem() { printf("%f", Tem); }
};

class Fahrenheit {
public:
	double Tem;
	Fahrenheit(){}//�ʱ�ȭ
	Fahrenheit(double aTem):Tem(aTem){}//�ʱ�ȭ ����Ʈ
	operator Celsius();//��ȯ
	void OutTem() { printf("%f\n", Tem); }//���
};
Celsius::operator Fahrenheit() {//�Ҽ� ���ΰ�
	Fahrenheit F;
	F.Tem = Tem * 1.8 + 32;
	return F;
}
Fahrenheit::operator Celsius() {//�Ҽ� ���ΰ�
	Celsius C;
	C.Tem = (Tem - 32) / 1.8;
	return C;
}

int main() {
	Celsius C(100);
	Fahrenheit F = C;
	C.OutTem();
	F.OutTem();

	printf("\n");
	Fahrenheit F = C;
	C.OutTem();
	F.OutTem();

	printf("\n");
	Fahrenheit F2 = 120;
	Celsius C2 = F2;
	F2.OutTem();
	C2.OutTem();
}