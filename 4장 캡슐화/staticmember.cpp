//#include <iostream>
//
//class StaticTest {//클래스는 주조물틀 같은 거고, 객체는 주조물 틀에서 만들어지는 칼같은 거다.
//	static int a;//static 멤버변수
//	int b;
//public:
//	StaticTest();
//	static void setData(int);//static이라는 멤버함수는 static 멤버변수에 사용한다.
//	void getData();
//};
//int StaticTest::a = 10;	//static 멤버변수 초기화
//StaticTest::StaticTest() {//포함되어 있다는 것이다.
//	this->b = 20;//원칙은 이 형식이 맞다. 일반적인 멤버변수는 이 형식을 따른다.
//}
//void StaticTest::getData() {
//	printf("a : %d,b : %d\n", a,b);
//}
//void StaticTest::setData(int aa) {
//	//this->a=aa; //this 포인터를 사용할 수 없다(즉 객체에 포함되지 않는다.) 객체의 것이 아니라 클래스의 것이다.
//	a = aa;//객체의 것이 아니기 때문에 this->을 쓸 수 없다. static은 정적으로 클래스에 달라붙어 있는 것이다. 데이터 값을 보존하는 것이다.
//}
//int main() 
//{
//	StaticTest s1;
//	s1.getData();
//	StaticTest s2;
//	s2.getData();
//
//	s1.setData(30);
//	s1.getData();
//	s2.getData();
//
//	StaticTest::setData(40);//주조물 틀을 아예 바꿔버리니까 모든 객체가 영향이 받는 것이다.
//	//클래스 소속으로 클래스로 호출이 가능하다.
//	s1.getData();
//	s2.getData();
//	return 0;
//}