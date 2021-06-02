#include <iostream>

class MyTest {
private:
	int x;//Ŭ������ x���� ������ �Ű������̴�.
	int y;//Ŭ������ y���� ������ �Ű������̴�.
public:
	MyTest(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
	MyTest sum(MyTest& other) {
		MyTest res;//� ��ü���� �����ؼ� ��������� �ø���.
		res.x = this->x + other.x;
		res.y = this->y + other.y;
		return res;
	}
	void printData() {
		printf("x: %d, y: %d", x, y);//���� ���� ������ ���� ȣ�� ��Ʈ���� ó���� �Ǿ��� ������ ���� ���� x,y�� ����Ǿ� ��µȴ�.
	}
};

int main() {
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.sum(obj2);//������ �ִ� ���� x���� ���� �ֶ� ���� x���� ���� ��� �Ѵ�.
	obj.printData();
	return 0;
}