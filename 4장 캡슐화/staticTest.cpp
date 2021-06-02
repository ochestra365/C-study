//#include <iostream>
//
//class statictest {
//public:
//	int a;
//	static int b;	// static 멤버변수 선언
//	statictest() {//생성자
//		a = 10;
//		//b = 20;	//클래스 내부에서 초기화는 안된다.
//		b++;
//	}
//	void getdata() {
//		printf("a : %d, b : %d\n", a,b);
//	}
//};
//int statictest::b = 20;// 소속은 반드시 표기해 주어야 한다. 외부에서 출력할 때느 소속이 필요하다. ->객체내에 존재하지 않는다.
////static 멤버 변수 초기화(외부에서 초기화한다.)
//int main() {
//	statictest s1;
//	s1.getdata();
//	statictest s2;
//	s2.getdata();
//	
//	return 0;
//}