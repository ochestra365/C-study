//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string s1("test");//생성
//	string s2(s1);//복사
//	string s3;//디폴트도 되고
//	string s4(10, 'S');// 연산도 되고
//	string s5("very nice day", 8);//글자 잘라먹는 거도 되고
//	const char* str = "abcdefghijklmnopqrstuvwxyz"; // 컴파일러 방식 const를 붙여서 상수라는 것을 알려준다.
//	string s6(str + 5, str + 10);//범위 지정도 된다.(start+1부터 end까지 출력) 문자열에서 한 문자를 통해서 바꾸는 것도 가능하다.
//
//	cout << "s1=" << s1 << endl;
//	cout << "s2=" << s2 << endl;
//	cout << "s3=" << s3 << endl;
//	cout << "s4=" << s4 << endl;
//	cout << "s5" << s5 << endl;
//	cout << "s6" << s6 << endl;
//	return 0;
//}