#include <iostream>

class MyTest {
private:
	int x;
	int y;
public:
	MyTest(){}
	MyTest(int ax, int ay) { x = ax; y = ay; }
	const MyTest sum(const MyTest& Other)const {
		MyTest My;
		My.x = x + Other.x;
		My.y = y + Other.y;
		return My;
	}
	void printData() {
		printf("x : %d, y: %d", x, y);
	}
};


int main(){
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.sum(obj2);
	obj.printData();
	return 0;
}