//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string s("C++ string");
//
//	cout << s << "문자열의 길이=" << s.size() << endl;
//	cout << s << "문자열의 길이=" << s.length() << endl;
//	cout << s << "문자열의 할당 크기=" << s.capacity() << endl;
//	cout << s << "문자열의 최대 길이" << s.max_size() << endl;
//
//	s.resize(6);//버퍼크기를 6개로 재할당한다.
//	cout << s << "길이 = " << s.size() << ",할당크기=" << s.capacity() << endl;
//	s.reserve(100);//버퍼의 크기를 재할당한다. 예약하다. 보존하다.
//	cout << s << "길이 = " << s.size() << ", 할당 크기=" << s.capacity() << endl;
//	cout << s.at(0) << endl;//버퍼 인덱스 값을 출력
//	s.clear();//지우는 것.==>사이즈는 그대로다. 안의 값들을 죄다 지워준다.
//	return 0;
//}