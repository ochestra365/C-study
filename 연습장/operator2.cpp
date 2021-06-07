#include <iostream>

class MyTest {
private:
	int x;
	int y;
public:
	MyTest() {}
	MyTest(int ax, int ay) {
		x = ax;
		y = ay;
		printf("인수 2개 생성자\n");
	}
	MyTest(MyTest& rhs) :x(rhs.x), y(rhs.y) {
		printf("복사생성자 호출!!\n");
	}
	const MyTest operator+(const MyTest& other)const {
		MyTest i;
		i.x = x + other.x;
		i.y = y + other.y;
		return i;
	}
	const MyTest operator-(const MyTest& Other)const {
		MyTest j;
		j.x = x - Other.x;
		j.y = y - Other.y;
		return j;
	}
	const MyTest& operator=(const MyTest& other) {
		x = other.x;
		y = other.y;
	}
	void printData() {
		printf("x : %d, y: %d\n", x, y);
	}
};
MyTest operator-(const MyTest& rhs1, const MyTest& rh2) {
	MyTest res;
}

int main() {
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	MyTest obj5;
	obj = obj1 + obj2;
	//obj5 = obj2 - obj1;
	obj.printData();
	obj = operator-(obj1, obj2);
	obj.printData();
	return 0;
}