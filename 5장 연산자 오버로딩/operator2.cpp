#include <iostream>//입출력 스트림으로 날려준다.

class MyTest {//클래스 생성
private:
	int x;//클래스의 x값을 저장할 매개변수이다.
	int y;//클래스의 y값을 저장할 매개변수이다.
public:
	MyTest() {}//초기생성자를 만들어준다.

	MyTest(int ax, int ay) { 
		x = ax; //메인에서 복사받은 것을 멤버변수 x로 올린다.
		y = ay; //메인에서 복사받은 것을 멤버변수 y로 올린다.
		printf("인수 2개 생성자!!\n");//그럼 인수 2개가 만들어 진다.
	}//생성자가 호출될 때마다  다음의 값을 메인에서 복사해서 생성한다.
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) {//이것을 통해서 임시객체가 만들어진다.
		printf("복사생성자 호출!!\n");
	}
	const MyTest operator+(const MyTest& other) const {//원래 나의 Mytest값에다가 다음. 참조자는 매개변수로 사용된다. 출력일 때 매개변수로 사용된다.
		//MyTest에 참조가 없으면 복사 생성자를 만들어야 한다.
		MyTest i;//새로운 Mytest i 클래스를 만든다.
		i.x = x+other.x;//다른 레퍼런스를 다운 받아서 기존의 값과 더해준 res값을 x에 넣어준다.
		i.y = y + other.y;//다른 레퍼런스를 다운 받아서 기존의 값과 더해준 res값을 y에 넣어준다.
		return i;//함수를 호출한 부분에 Mytest를 반환한다.
		//참조의 참조값을 던져줘야 한다.
	}
	const MyTest operator-(const MyTest& Other)const {//위의 로직과 완전히 같은 개념 만들어진 객체도 const타입으로 설정하겠다는 의미이다.
		MyTest j;
		j.x = x - Other.x;
		j.y = y - Other.y;
		return j;
	}
	const MyTest& operator = (const MyTest& other) {
		//MyTest X; const 를 삭제하면 호출하는 객체가 상수화 되서 수정할 수 없다.
		x = other.x;
		y = other.y;
		return *this;//포인터를 써서 필드의 매개변수로 띄워준다.
	}
	void printData() {
		printf("x: %d, y: %d\n", x, y);//더한 것의 데이터 값은 호출 파트에서 처리가 되었기 때문에 더한 값이 x,y에 저장되어 출력된다.
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