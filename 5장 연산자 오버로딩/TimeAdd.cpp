#include <iostream>

class MyTest {
private:
	int x;//Ŭ������ x���� ������ �Ű������̴�.
	int y;//Ŭ������ y���� ������ �Ű������̴�.
public:
	MyTest() {}//�ʱ�����ڸ� ������ش�.

	MyTest(int ax, int ay) { x = ax; y = ay; }//�����ڰ� ȣ��� ������  ������ ���� ���ο��� �����ؼ� �����Ѵ�.

	const MyTest sum(const MyTest& Other) const {//const �����ڸ� �Ἥ ������ Ŭ������ ������ش�. �̶� �������� ������ ���ؼ� const�� ���ش�.
		//�̋� �Ű������� ���� ���簪�� ���ȭ�����༭ �ܼ� ������ �ϰ� �Ѵ�.
		//sum���� other�� ���۷����� �޾Ƽ� other�� ħ������ �ʴ´�. // ����� ���� const�̴�.
		MyTest My; // ���� sum�Լ��� �޸𸮿��� �ֹߵǱ� ������ My�� ���尴ü�� �ϳ� �������ش�.
		My.x = x + Other.x;//���簪�� �Ű��������� ���ؼ� MY�� �����Ѵ�.
		My.y = y + Other.y;
		return My;//MyŬ������ �Լ��� ȣ���� ���� ��ȯ�ϴ�.
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