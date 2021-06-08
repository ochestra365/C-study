#include <iostream>
using namespace std;

template <typename T>// 일반화된 템플릿에 의해서 적용됨
T Add(T a, T b) {
	return a + b;
}

template<>	//특수화
const char* Add(const char* lstr, const char* rstr) {
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;//전체 문자열의 길이
	char* str = new char[len];
	strcpy_s(str, llen + 1, lstr);
	strcat_s(str, len, rstr);
	return str;
}
int main() 
{
	int res = Add<int>(3, 4);//일반화 5번 행 실행
	cout << res << endl;
	const char* sres =  Add<const char*>("Hello", "Iot"); //10행 실행
	cout << sres << endl;
	return 0;
}