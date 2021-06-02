#include <iostream>

class MyTest {
private:
	int x;//클래스의 x값을 저장할 매개변수이다.
	int y;//클래스의 y값을 저장할 매개변수이다.
public:
	MyTest() {}//초기생성자를 만들어준다.

	MyTest(int ax, int ay) { x = ax; y = ay; }//생성자가 호출될 때마다  다음의 값을 메인에서 복사해서 생성한다.

	const MyTest sum(const MyTest& Other) const {//const 연산자를 써서 저장할 클래스를 만들어준다. 이때 데이터의 보존을 위해서 const를 써준다.
		//이떄 매개변수로 받은 복사값은 상수화시켜줘서 단순 더함을 하게 한다.
		//sum으로 other의 레퍼런스를 받아서 other는 침해하지 않는다. // 결과값 또한 const이다.
		MyTest My; // 여기 sum함수의 메모리에서 휘발되긴 하지만 My로 저장객체를 하나 생성해준다.
		My.x = x + Other.x;//복사값과 매개변수값을 더해서 MY로 저장한다.
		My.y = y + Other.y;
		return My;//My클래스를 함수를 호출한 곳에 반환하다.
	}
	void printData() {
		printf("x: %d, y: %d", x, y);//더한 것의 데이터 값은 호출 파트에서 처리가 되었기 때문에 더한 값이 x,y에 저장되어 출력된다.
	}
};

int main() {
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.sum(obj2);//가지고 있는 것의 x값에 원래 있떤 것의 x값을 더해 줘야 한다.
	obj.printData();
	return 0;
}