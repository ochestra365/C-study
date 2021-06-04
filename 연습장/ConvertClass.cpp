#include <stdio.h>
class Fahrenheit;//선언
class Celsius {
public:
	double Tem;
	Celsius(){}//초기화
	Celsius(double aTem):Tem(aTem){}//초기화 리스트
	operator Fahrenheit();//변환
	void OutTem() { printf("%f", Tem); }
};

class Fahrenheit {
public:
	double Tem;
	Fahrenheit(){}//초기화
	Fahrenheit(double aTem):Tem(aTem){}//초기화 리스트
	operator Celsius();//변환
	void OutTem() { printf("%f\n", Tem); }//기능
};
Celsius::operator Fahrenheit() {//소속 서로간
	Fahrenheit F;
	F.Tem = Tem * 1.8 + 32;
	return F;
}
Fahrenheit::operator Celsius() {//소속 서로간
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