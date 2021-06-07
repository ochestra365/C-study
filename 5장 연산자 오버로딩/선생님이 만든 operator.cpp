#include <iostream>

class MyTest {
private:
	int x;//클래스의 x값을 저장할 매개변수이다.
	int y;//클래스의 y값을 저장할 매개변수이다.
public:
	MyTest(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
	MyTest sum(MyTest& other) {
		MyTest res;//어떤 객체에서 저장해서 멤버변수로 올린다.
		res.x = this->x + other.x;
		res.y = this->y + other.y;
		return res;
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