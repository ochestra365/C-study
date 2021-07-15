#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;//배열을 벡터를 통해서 지정할 수 있다. 배열같이 쓸 수 있다.
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2[5];

	v.push_back(10);
	vector<int> ::iterator iter = v.begin();//객체인데 포인터같은 객체이다. 템플릿으로 만들어진 라이브러리를 사용할 수 있다. 템플릿 라이브러리를 제어할 수 있다.
	iter = v.insert(iter, 2);//v라는 vector에 2라는 값을 집어넣어라 
	v.pop_back();
	v.erase(v.begin()+10);
	v.clear();
	return 0;
}
