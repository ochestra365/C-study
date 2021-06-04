#include <iostream>//����� ��Ʈ������ �����ش�.

class MyTest {//Ŭ���� ����
private:
	int x;//Ŭ������ x���� ������ �Ű������̴�.
	int y;//Ŭ������ y���� ������ �Ű������̴�.
public:
	MyTest() {}//�ʱ�����ڸ� ������ش�.

	MyTest(int ax, int ay) { 
		x = ax; //���ο��� ������� ���� ������� x�� �ø���.
		y = ay; //���ο��� ������� ���� ������� y�� �ø���.
		printf("�μ� 2�� ������!!\n");//�׷� �μ� 2���� ����� ����.
	}//�����ڰ� ȣ��� ������  ������ ���� ���ο��� �����ؼ� �����Ѵ�.
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) {//�̰��� ���ؼ� �ӽð�ü�� ���������.
		printf("��������� ȣ��!!\n");
	}
	const MyTest operator+(const MyTest& other) const {//���� ���� Mytest�����ٰ� ����. �����ڴ� �Ű������� ���ȴ�. ����� �� �Ű������� ���ȴ�.
		//MyTest�� ������ ������ ���� �����ڸ� ������ �Ѵ�.
		MyTest i;//���ο� Mytest i Ŭ������ �����.
		i.x = x+other.x;//�ٸ� ���۷����� �ٿ� �޾Ƽ� ������ ���� ������ res���� x�� �־��ش�.
		i.y = y + other.y;//�ٸ� ���۷����� �ٿ� �޾Ƽ� ������ ���� ������ res���� y�� �־��ش�.
		return i;//�Լ��� ȣ���� �κп� Mytest�� ��ȯ�Ѵ�.
		//������ �������� ������� �Ѵ�.
	}
	const MyTest operator-(const MyTest& Other)const {//���� ������ ������ ���� ���� ������� ��ü�� constŸ������ �����ϰڴٴ� �ǹ��̴�.
		MyTest j;
		j.x = x - Other.x;
		j.y = y - Other.y;
		return j;
	}
	const MyTest& operator = (const MyTest& other) {
		//MyTest X; const �� �����ϸ� ȣ���ϴ� ��ü�� ���ȭ �Ǽ� ������ �� ����.
		x = other.x;
		y = other.y;
		return *this;//�����͸� �Ἥ �ʵ��� �Ű������� ����ش�.
	}
	void printData() {
		printf("x: %d, y: %d\n", x, y);//���� ���� ������ ���� ȣ�� ��Ʈ���� ó���� �Ǿ��� ������ ���� ���� x,y�� ����Ǿ� ��µȴ�.
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
	obj = obj1+obj2;
	//obj5 = obj2 - obj1;
	//obj = obj1.operator=(obj2);
	obj.printData();
	//obj5.printData();
	obj = operator-(obj1, obj2);
	obj.printData();
	return 0;
}