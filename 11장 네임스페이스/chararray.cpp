//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string s("char array");
//	string s1("C++ string");
//	cout << s.data() << endl;//NULL문자가 들어가지 않는다.
//	cout << s.c_str() << endl;//NULL문자가 맨 끝에 들어간다.
//
//	char str[128];
//	strcpy(str, s.c_str());
//	printf("str=%s\n", str);
//
//	swap(s, s1);//굉장히 편하다. swap함수 호출해서 바로 스트링 객체를 넘겨주니까 자동으로 바꾼다.
//	cout << s << endl;//굉장히 편하다.
//}